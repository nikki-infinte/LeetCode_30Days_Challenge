class Solution {
public:
    int countSubstrings(string s) {
        
        int n =s.length();
        vector<vector<bool>>t(n,vector<bool>(n,false));
        int count=0;

        for(int len = 1; len <= n ;len ++)
        {
            for(int i=0;i+len-1<n;i++)
            {
                int j = i+len-1;
                if(i == j)
                {
                    //len 1 
                    t[i][j] = true;
                }else if(i+1  == j){
                    t[i][j]=(s[i] == s[j]);
                }else{
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }

                if(t[i][j])count++;
            }
        }
        return count;
    }
};