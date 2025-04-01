class Solution {
public:

    long long TakeNot(vector<vector<int>>& que , int indx,vector<long long>&dp)
    {
        if(indx>=que.size())return 0;

        if(dp[indx]!=-1)
        {
            return dp[indx];
        }
    
            long long take =que[indx][0]+TakeNot(que,indx+que[indx][1]+1,dp);
        
        long long nottake = TakeNot(que,indx+1,dp);
        return dp[indx]=max(take , nottake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n+1,-1);
        return TakeNot(questions,0,dp);
    }
};