class Solution {
public:

    bool solve(int indx,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(indx >= nums.size()){
            return target == 0;
        }
        if(target ==0)return true;
        if(target < 0 )return false;

        if(dp[indx][target]!=-1){
            return dp[indx][target];
        }
        bool take = solve(indx+1,target-nums[indx],nums,dp);
        bool notT= solve(indx+1,target,nums,dp);

        return dp[indx][target] = take || notT;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        int x= total/2;

        if(total % 2 !=0)return false;
        vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
        return solve(0,x,nums,dp);
    }
};