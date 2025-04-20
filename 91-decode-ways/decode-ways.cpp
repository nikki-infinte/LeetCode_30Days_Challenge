class Solution {
public:
   int function_Recursion(string& s, int indx, unordered_map<int, int>& dp)
    { 
       if(indx == s.length())
       {
        return 1;
       }
       if(s[indx] =='0')return 0;
        if (dp.find(indx) != dp.end()) return dp[indx];
        int ways =0;

        ways+=function_Recursion(s,indx+1,dp);

        if(indx+1<s.length()){
            int n =(s[indx]-'0')*10+(s[indx+1]-'0');
            if(n >=10 && n <=26)
            {
                ways+=function_Recursion(s, indx + 2, dp);
            }
        }
         return dp[indx] = ways;
    }
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        return function_Recursion(s, 0, dp);
       
    }
};