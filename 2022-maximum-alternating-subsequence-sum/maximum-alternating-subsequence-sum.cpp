 const int MAXN =100005;
class Solution {
public:
  
    long long solve(int indx, bool isEven, vector<int>& nums,long long dp[MAXN][2]) {
        // base
        if (indx >= nums.size()) {
            return 0;
        }
        if (dp[indx][isEven] != -1) {
            return dp[indx][isEven];
        }

        long long skip = solve(indx + 1, isEven, nums,dp);
        long long val = nums[indx];

        if (!isEven) {
            val = (-val);
        }
        long long take = solve(indx + 1, !isEven, nums,dp) + val;
        return dp[indx][isEven] = max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
       int n= nums.size();
        long long dp[MAXN][2];
      memset(dp, -1, sizeof(dp));
        return solve(0, true, nums,dp);
    }
};