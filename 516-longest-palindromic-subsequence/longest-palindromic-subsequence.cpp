class Solution {
public:

    int n ;
    int LCS(string& s1,string&s , int i,int j ,vector<vector<int>>&dp)
    {
        //base case
        if(i < 0 || j < 0)return 0;
        if( i ==0 || j== 0){
            if(s[0] == s1[0])
                return 1;
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        //recursive call 
        if(s1[i] == s[j]){
            return dp[i][j] = 1 + LCS(s1,s,i-1,j-1,dp); 
        }else{
            return dp[i][j] = max(LCS(s1,s,i-1,j,dp) , LCS(s1,s,i,j-1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {

        n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        string s1 = s;
        reverse(s.begin(),s.end());
       // return LCS(s1,s,n,n,dp);

        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int j=0;j<=n;j++){
            dp[0][j] = 0;
        }
       for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1] == s1[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
       }

       return dp[n][n];
    }
};