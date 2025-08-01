class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long>>dp(n+1,vector<long>(2,0));

        for(int i=1;i<n+1;i++){
            dp[i][0] = max(dp[i-1][1]-nums[i-1] , dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0]+ nums[i-1] , dp[i-1][1]);
        }
        return max(dp[n][0],dp[n][1]);
    }
};