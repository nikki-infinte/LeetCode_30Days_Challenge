class Solution {
public:

    int solve(int i,int prevTake,vector<int>&nums,vector<vector<int>>&dp){
        
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i][prevTake+1] != -1){
            return dp[i][prevTake+1];
        }
        //take
        int take =0;
        if(prevTake == -1 || nums[i] > nums[prevTake]){
            take = 1+solve(i+1,i,nums,dp);
        } 
        //not take 
        int notTake = solve(i+1,prevTake,nums,dp);
        return dp[i][prevTake+1] = max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        return solve(0,-1,nums,dp);
    }
};