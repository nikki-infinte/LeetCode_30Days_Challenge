class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<char> ch;
        string ans="";
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            {
                //opening brackets 
                count++;
                if(count>1) ch.push_back(s[i]);
            }else{
                count--;
                if(count > 0) ch.push_back(s[i]);

            }
        }

        for(int i=0;i<ch.size();i++)
        {
            ans +=ch[i];
            
        }
        return ans;
    }
};