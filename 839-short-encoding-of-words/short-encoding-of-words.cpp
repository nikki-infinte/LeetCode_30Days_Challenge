class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {

        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int n = words.size();
        string ans = "";
        set<string> EndsWith;
        for (int i = n - 1; i >= 0; i--) {

            if (EndsWith.find(words[i]) != EndsWith.end()) {
                continue;
            } else {
                string str = "";
                for (int j = words[i].size() - 1; j >= 0; j--) {
                    str = words[i][j] + str;
                    EndsWith.insert(str);
                }

                ans += words[i];
                ans += "#";
            }
        }
        return ans.length();
    }
};