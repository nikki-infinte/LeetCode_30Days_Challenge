class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int countRe = t.length();
        int i = 0, j = 0;

        unordered_map<char, int> umap;
        for (char c : t) {
            umap[c]++;
        }

        int minlen = INT_MAX;
        int start_i = 0;

        while (j < n) {
            if (umap[s[j]] > 0) countRe--;
            umap[s[j]]--;

            while (countRe == 0) {
                if (j - i + 1 < minlen) {
                    minlen = j - i + 1;
                    start_i = i;
                }

                umap[s[i]]++;
                if (umap[s[i]] > 0) countRe++;
                i++;
            }

            j++;
        }

        return minlen == INT_MAX ? "" : s.substr(start_i, minlen);
    }
};
