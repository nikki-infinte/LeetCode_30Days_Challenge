class Solution {
public:
    int backtrack(int index,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(index >=nums.size())
        {
            return 0;
        }
        if (dp[index][prev + 1] != -1) {
            return dp[index][prev + 1]; // Return cached result
        }

        //not include
        int maxlen=0+backtrack(index+1, prev,nums,dp);
       if (prev == -1 || nums[prev] < nums[index]) {
            maxlen = max(maxlen, 1 + backtrack(index + 1, index, nums, dp));
        }
     dp[index][prev + 1] = maxlen; // Cache the result
        return maxlen;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
 vector<vector<int>> dp(n, vector<int>(n + 1, -1));
      
     return backtrack(0,-1,nums,dp);
    }
};