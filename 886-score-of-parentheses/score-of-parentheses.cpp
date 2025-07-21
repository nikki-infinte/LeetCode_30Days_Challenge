class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string>st;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push("(");
            }else if(s[i] ==')'){
                int tmp =0;
                while(!st.empty() && st.top()!="("){
                    tmp += stoi(st.top());
                    st.pop();
                }
                st.pop();
                 if(tmp == 0) {
                    st.push("1");
                } else {
                    st.push(to_string(2 * tmp));
                }
            }
        }

        int score =0;
        while(!st.empty()){
            score+=stoi(st.top());
            st.pop();
        }
        return score;
    }
};