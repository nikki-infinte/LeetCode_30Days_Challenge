class Solution {
public:
    //problem of backtracking 
    void gen(int n,int open,int close,string s,vector<string>&ans)
    {
        if(open==n && close ==n)
        {
            ans.push_back(s);
            return;
        }
        if(open<n)
        {
            gen(n,open+1,close,s+'(',ans);
        }

        if(close < open)
        {
            gen(n,open,close+1,s+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        gen(n,0,0,s,ans);
        return ans;
    }
};