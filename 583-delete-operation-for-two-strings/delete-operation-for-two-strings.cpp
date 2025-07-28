class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int solve(int i,int j,string& word1,string& word2){

        //base case
        if(j == m && i < n){
            return n-i;
        }
        if( i == n && j < m){
            return m-j;
        }
        if(i == n || j == m)return 0;

        if(dp[i][j] !=-1)return dp[i][j];
        //recursive
        if(word1[i] == word2[j]){
            return dp[i][j] = solve(i+1,j+1,word1,word2);
        }else{
            return dp[i][j] = 1+min(solve(i+1,j,word1,word2) , solve(i,j+1,word1,word2));
        }
    }


    
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        dp.resize(n,vector<int>(m,-1));

        return solve(0,0,word1,word2);
    }
};