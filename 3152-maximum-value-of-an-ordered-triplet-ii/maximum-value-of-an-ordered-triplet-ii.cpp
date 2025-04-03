class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // No triplet possible

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);

        // Compute left max excluding the current element
        leftMax[0] = INT_MIN; // No valid left element for index 0
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i - 1]); // Use nums[i-1]
        }

        // Compute right max excluding the current element
        rightMax[n - 1] = INT_MIN; // No valid right element for last index
        for (int j = n - 2; j >= 0; j--) {
            rightMax[j] = max(rightMax[j + 1], nums[j + 1]); // Use nums[j+1]
        }

        long long res = 0;
        for (int i = 1; i < n - 1; i++) {
            int l = leftMax[i]; // Max before i
            int r = rightMax[i]; // Max after i
            if (l != INT_MIN && r != INT_MIN) {
                res = max(res, (long long)(l - nums[i]) * r);
            }
        }

        return res;
    }
};
