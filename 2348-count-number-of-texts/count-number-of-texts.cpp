class Solution {
public:

    int MOD = 1e9+7;
    int add(int x,int y)
    {
        return (x%MOD + y%MOD)%MOD;
    }
    int countTexts(string s) {
        

        int n = s.length();
        vector<int>dp(n+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++)
        {
            dp[i] = dp[i-1];

            //try 2 -charater group
            if(i>=2 && s[i-1] == s[i-2])
            {
                dp[i] = add(dp[i],dp[i-2]);
            }

              if (i >= 3 && s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) {
                dp[i] = add(dp[i], dp[i - 3]);
            }

               if (i >= 4 && s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3] && s[i - 3] == s[i - 4]) {
                if (s[i - 1] == '7' || s[i - 1] == '9') {
                    dp[i] = add(dp[i], dp[i - 4]);
                }
            }


        }
        return dp[n];

    }
};