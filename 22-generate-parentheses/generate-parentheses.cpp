class Solution {
public:

   void generate_pranthese(int open,int close,string s,vector<string>&res)
{
    if(open==0 && close==0)
    {
       res.push_back(s);
        return ;
    }
    
    if(open >0)
    {
          generate_pranthese(open-1,close,s+'(',res);
    }
    
    if(close > open)
    {
          generate_pranthese(open,close-1,s+')',res);
    }
}
    vector<string> generateParenthesis(int n) {
         vector<string>res;
     generate_pranthese(n,n,"",res);
     return res;
    }
};