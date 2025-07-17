class Solution {
public:
    bool series(string st1) {
        for (char c : st1) {
            if (c < 'a' || c > 'z')
                return false;
        }
        return true;
    }

    bool isdigitStr(string st2) {
        for (char c : st2) {
            if (!isdigit(c))
                return false;
        }
        return true;
    }

    string decodeString(string str) {
        stack<string> st;
        int n = str.length();

        for (int i = 0; i < n; i++) {

            if (isdigit(str[i])) {
                int j = i;
                string num = "";
                while (j < n && isdigit(str[j])) {
                    num += str[j++];
                }
                st.push(num);
                i = j - 1;
            }

            else if (str[i] == '[') {
                st.push("[");
            }

            else if (str[i] >= 'a' && str[i] <= 'z') {
                string tmp = "";
                tmp += str[i];
                st.push(tmp);
            }

            else if (str[i] == ']') {
                // build the string inside []
                string app = "";
                while (!st.empty() && st.top() != "[") {
                    app = st.top() + app;
                    st.pop();
                }

                if (!st.empty() && st.top() == "[") st.pop(); // pop the '['

                int time = 1;
                if (!st.empty() && isdigitStr(st.top())) {
                    time = stoi(st.top());
                    st.pop();
                }

                string repeated = "";
                for (int k = 0; k < time; k++) {
                    repeated += app;
                }

                st.push(repeated); // push back the decoded string
            }
        }

        // Build the final answer from stack
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};
