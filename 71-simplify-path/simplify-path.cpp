class Solution {
public:
    string simplifyPath(string path) {
        

        stringstream ss(path);
        string word;

        stack<string>st;
        while(getline(ss,word,'/'))
        {
            if(word == "" || word == ".")continue;

          if(word == "..")
            {
                if(!st.empty())  {
                    st.pop();
                }
            } 
            else st.push(word);
        }

        string ans = "";
        while(!st.empty())
        {
            ans ="/"+st.top()+ans;
            st.pop();
        }

       return ans.empty() ? "/" : ans; 
    }
};