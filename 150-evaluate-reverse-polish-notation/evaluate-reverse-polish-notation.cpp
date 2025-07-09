class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
   
        stack<string>st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i] == "+" || tokens[i] == "*" || tokens[i]=="/" || tokens[i] =="-"){
                int op1 = stoi(st.top());
                st.pop();
                int op2 = stoi(st.top());
                st.pop();


                if(tokens[i] == "+"){
                    st.push(to_string(op2+op1));
                }else if(tokens[i] == "-"){
                    st.push(to_string(op2-op1));
                }else if(tokens[i] == "*"){ 
                    st.push(to_string(op2*op1));
                }else{
                    st.push(to_string(op2/op1));
                }
            }else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};