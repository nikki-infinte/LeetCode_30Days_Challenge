class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if (t.length() > n) return "";

        unordered_map<char, int> umap;
        for (auto c : t) umap[c]++;

        int i = 0, j = 0;
        int countRequired = t.size();
        int windowSize = INT_MAX, start_i = 0;

        while (j < n) {
            char ch = s[j];
            if (umap[ch] > 0) countRequired--;
            umap[ch]--;

            while (countRequired == 0) {
                if (j - i + 1 < windowSize) {
                    windowSize = j - i + 1;
                    start_i = i;
                }

                umap[s[i]]++;
                if (umap[s[i]] > 0) countRequired++;
                i++;
            }
            j++;
        }

        return windowSize == INT_MAX ? "" : s.substr(start_i, windowSize);
    }
};
