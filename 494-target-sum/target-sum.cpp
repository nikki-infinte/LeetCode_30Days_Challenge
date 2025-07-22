class Solution {
public:
    unordered_map<string,int>dp;
    int solve(int indx, vector<int>& nums, int sum, int target ) {
        if (indx >= nums.size()) {
            if (sum == target)
               return 1;
            return 0;
        }
        string key = to_string(indx)+','+to_string(sum);
        if(dp.count(key))return dp[key];
        int pos = solve(indx + 1, nums, sum + nums[indx], target );
        int neg = solve(indx + 1, nums, sum - nums[indx], target);
        return dp[key] =pos+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
      
       dp.clear();
    return solve(0, nums, 0, target);
    }
};