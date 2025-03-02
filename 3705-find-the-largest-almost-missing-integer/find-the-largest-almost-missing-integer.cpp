class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Case: k == 1 -> Find largest unique number
        if (k == 1) {
            sort(nums.begin(), nums.end());

            for (int i = n - 1; i >= 0; i--) {
                // Ensure nums[i] is unique
                if ((i == 0 || nums[i] != nums[i - 1]) && (i == n - 1 || nums[i] != nums[i + 1])) {
                    return nums[i];
                }
            }
            return -1; // All elements are duplicates
        }

        // Case: k != n and all elements are the same -> Return -1
        if (k != n && nums[0] == nums[n - 1]) return -1;

        // Case: k == n -> Simply return the max element
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Checking for first_red and last_red
        bool first_red = false, last_red = false;
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] == nums[0]) first_red = true;
            if (nums[i] == nums[n - 1]) last_red = true;
        }

        if (!first_red && !last_red) return max(nums[0], nums[n - 1]);
        if (first_red && !last_red) return nums[n - 1];
        if (!first_red && last_red) return nums[0];

        return -1;
    }
};
