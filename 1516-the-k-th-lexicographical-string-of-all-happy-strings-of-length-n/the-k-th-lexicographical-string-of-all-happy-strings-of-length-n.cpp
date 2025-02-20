class Solution {
public:
    void generate(int n, vector<string>& org, vector<string>& ans, string tmp) {
        if (tmp.size() == n) {
            ans.push_back(tmp);
            return;  // Important to stop further recursion
        }

        for (int i = 0; i < org.size(); i++) {
            if (tmp.empty() || tmp.back() != org[i][0]) {
                generate(n, org, ans, tmp + org[i]);  // Pass modified string
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> org = {"a", "b", "c"};
        vector<string> ans;
        
        generate(n, org, ans, "");
        
        if (k > ans.size()) return "";
        sort(ans.begin(), ans.end());  // Sort to get lexicographical order
        
        return ans[k - 1];  // Return the k-th lexicographically smallest string
    }
};
