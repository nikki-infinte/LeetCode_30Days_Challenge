class Solution {
public:
vector<vector<int>>dp;
    bool solve(string& s,string& p,int i,int j)
    {
        //base case 
        if( i < 0 && j < 0)return true;
        if( j < 0 && i >= 0 )return false;
        if (i < 0 && j >= 0) {
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1)return dp[i][j];
        // recursive call 
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = solve(s,p,i-1,j-1);
        }else if( p[j] == '*'){
            return dp[i][j] = solve(s,p,i-1,j) || solve(s,p,i,j-1);
        }else{
            return dp[i][j] = false;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length()-1;
        int m = p.length()-1;
         dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(s,p,n,m);
    }
};