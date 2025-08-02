class Solution {
public:
    int n , m ,l;
    int dp[101][101];
    bool solve(int i,int j,string& s1,string& s2,string& s3){
        if( i== n && j == m )return true;
       if(dp[i][j] != -1)return dp[i][j];
        int  k = i+j;
        bool s1take = false;
        if(s1[i] == s3[k]){
            s1take = solve(i+1,j,s1,s2,s3);
        }
        bool s2take =false;
        if(s2[j] == s3[k]){
            s2take = solve(i,j+1,s1,s2,s3);
        }
        return dp[i][j] = s1take || s2take;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n = s1.length();
        m = s2.length();
        l = s3.length();

        memset(dp,-1,sizeof(dp));
        if(n+m != l)return false;
        return solve(0, 0, s1, s2, s3);

    }
};