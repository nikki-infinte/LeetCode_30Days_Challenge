class Solution {
public:

    int solve(int i , vector<int>&stones,int curSum ,vector<vector<int>>&dp,int target ){
        if( i == stones.size()){
            return curSum;
        }

        if( dp[i][curSum] !=-1)return dp[i][curSum];

        //not take;
        int notTake =solve(i+1,stones,curSum,dp,target);
        int take =curSum;
        if(take + stones[i] <= target) {
            take = solve(i+1,stones,take + stones[i],dp,target);
        }
        return dp[i][curSum] = max(notTake,take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(),stones.end(),0);
        int target = total /2;
        int n = stones.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));


        int maxSumSubset = solve(0,stones,0,dp,target);
        return total - 2*maxSumSubset;
    }
};