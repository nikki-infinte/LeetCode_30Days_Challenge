class Solution {
public:
    int n , m;

    int solve(int i,int j,string& word1,string word2 ,vector<vector<int>>&dp){

        if( i == n )return m-j;
        if( j == m )return n-i;

        if(dp[i][j] != -1)return dp[i][j];

        if(word1[i] == word2[j])return solve(i+1,j+1,word1,word2,dp);
        else{
            int in = 1+solve(i,j+1,word1,word2,dp);
            int de = 1+solve(i+1,j,word1,word2,dp);
            int rep = 1+solve(i+1,j+1,word1,word2,dp);

            return dp[i][j] = min({in,de,rep});
        }

    }
    int minDistance(string word1, string word2) {
        n  = word1.size();
        m  = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,word1,word2,dp);
    }
};