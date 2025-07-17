class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>());

        int i = 0;
        while(i < n){
            if(formula[i] == '('){
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i] == ')') {
                i++; // skip ')'
                unordered_map<string,int> curr = st.top();
                st.pop();

                // Parse multiplier
                string multi;
                while(i < n && isdigit(formula[i])){
                    multi.push_back(formula[i]);
                    i++;
                }

                int multInteger = multi.empty() ? 1 : stoi(multi);
                for(auto &it : curr){
                    it.second *= multInteger;
                }

                for(auto &it : curr){
                    st.top()[it.first] += it.second;
                }
            }
            else {
                string curr;
                curr.push_back(formula[i]);
                i++;
                while(i < n && isalpha(formula[i]) && islower(formula[i])){
                    curr.push_back(formula[i]);
                    i++;
                }

                string currCnt;
                while(i < n && isdigit(formula[i])){
                    currCnt.push_back(formula[i]);
                    i++;
                }

                int currCountInteger = currCnt.empty() ? 1 : stoi(currCnt);
                st.top()[curr] += currCountInteger;
            }
        }

        map<string,int> sortedMap(begin(st.top()), end(st.top()));
        string res;
        for(auto &it : sortedMap){
            res += it.first;
            if(it.second > 1){
                res += to_string(it.second);
            }
        }
        return res;
    }
};
