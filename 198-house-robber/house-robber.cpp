class Solution {
public:

    int backtrackDp(int n,vector<int>&nums,vector<int>&memo)
    {
        if( n >=nums.size())
        {
            return 0;
        }
        if(memo[n]!=-1)
        {
            return memo[n];
        }

        int take = nums[n]+backtrackDp(n+2,nums,memo);
        int nottake = backtrackDp(n+1,nums,memo);

        return memo[n] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>memo(n,-1);
        return backtrackDp(0,nums,memo);
        //adjacent
    }
};