class Solution {
public:

    int solve(int n,vector<int>&dp)
    {
        if(n==1)return 1;

        int res = INT_MIN;
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        for(int i=1;i<=n-i;i++)
        {
            int prod = i*max(n-i,solve(n-i,dp));
            res = max(prod,res);
        }
        return dp[n] = res;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};