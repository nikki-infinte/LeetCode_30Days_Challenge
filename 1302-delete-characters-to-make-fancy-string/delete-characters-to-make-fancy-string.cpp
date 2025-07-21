class Solution {
public:
    string makeFancyString(string s) {
        stack<pair<char,int>>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top().first == s[i]){
                if(st.top().second < 2){
                    st.push({s[i],2});
                }
            }else{
                st.push({s[i],1});
            }
        }

        string ans ="";
        while(!st.empty()){
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};