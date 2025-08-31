class Solution {
public:
    int solve(vector<int>& nums, int indx, int prevIndx, vector<vector<int>>& dp) {
        if (indx == nums.size()) return 0;

        if (dp[indx][prevIndx + 1] != -1) return dp[indx][prevIndx + 1];

        int take = 0;
        if (prevIndx == -1 || nums[indx] > nums[prevIndx]) {
            take = 1 + solve(nums, indx + 1, indx, dp);
        }

        int nottake = solve(nums, indx + 1, prevIndx, dp);

        return dp[indx][prevIndx + 1] = max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // prevIndx from -1 to n-1
        return solve(nums, 0, -1, dp);
    }
};
