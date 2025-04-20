class Solution {
public:
    string reverseWords(string s) {
        
        string output="";
        stack<string>st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
                output+=s[i];
            }
            else if (!output.empty()){
                st.push(output);
                output="";
            }
        }
        if(!output.empty()){
            st.push(output);
        }

        string ans ="";
        while(!st.empty())
        {
            string tmp =st.top();
            st.pop();
            ans+=tmp;
           if(!st.empty()) ans+=" ";
        }
    
        return ans;

    }
};