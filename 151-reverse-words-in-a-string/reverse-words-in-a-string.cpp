class Solution {
public:
    string reverseWords(string s) {
          stack<string> st;
        string res = "";
        string word = "";

        // Traverse the string and push words to the stack
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!word.empty()) {
                    st.push(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }

        // Push the last word to the stack if it exists
        if (!word.empty()) {
            st.push(word);
        }

        // Pop words from the stack and append them to the result
        while (!st.empty()) {
            res += st.top();
            st.pop();
            if (!st.empty()) {
                res += " ";
            }
        }

        return res;
    }
};