class Solution {
public:
    int solve(int prev,int indx,vector<vector<int>>& pairs,vector<vector<int>>&dp){
        if(indx >= pairs.size()){
            return 0;
        }

        if(dp[indx][prev+1] !=-1)return dp[indx][prev+1];
        int take =0;
        int nottake = solve(prev,indx+1,pairs,dp);
        if(prev== -1 || pairs[prev][1] < pairs[indx][0]){
            take = 1+solve(indx,indx+1,pairs,dp);
        }
        
        return dp[indx][prev+1]=max(take ,nottake);
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort interm of pairs[0]
        int n = pairs.size();
        sort(begin(pairs),end(pairs));
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(-1,0,pairs,dp);
    }
};