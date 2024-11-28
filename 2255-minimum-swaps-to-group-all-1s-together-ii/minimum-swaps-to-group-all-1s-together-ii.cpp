class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0;
        int n = nums.size();

        // Count the total number of 1s
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) ones++;
        }

        // If no 1s or all are 1s, no swaps are needed
        if (ones == 0 || ones == n) return 0;

        int min_zero = INT_MAX; // Minimum zeros (swaps needed)
        int zero = 0;

        // Sliding window on doubled array
        int i = 0;
        for (int j = 0; j < 2 * n; j++) {
            
            if (nums[j % n] == 0) zero++;

            // Shrink window if it exceeds size `ones`
            if (j - i + 1 > ones) {
                if (nums[i % n] == 0) zero--; // Remove the element going out
                i++;
            }

            // Update the minimum zeros count when window size is `ones`
            if (j - i + 1 == ones) {
                min_zero = min(min_zero, zero);
            }
        }

        return min_zero;
    }
};
