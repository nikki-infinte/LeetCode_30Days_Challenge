class Solution {
public:
    string removeDuplicateLetters(string s) {

        stack<char> res;
        vector<int> future(26, 0);
        vector<bool> trace(26, false);
        for (int i = 0; i < s.length(); i++) {
            future[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.length(); i++) {
            if (trace[s[i] - 'a'])
                continue;
            while (!res.empty() && res.top() > s[i] &&
                   future[res.top() - 'a'] > i) {
                trace[res.top()- 'a'] = false;
                res.pop();
                
            }

            res.push(s[i]);
            trace[res.top() - 'a'] = true;
        }
        string ans = "";
        while (!res.empty()) {
            ans += res.top();
            res.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};