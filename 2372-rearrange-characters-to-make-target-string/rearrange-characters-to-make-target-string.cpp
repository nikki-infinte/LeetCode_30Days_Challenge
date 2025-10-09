class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> freq;
        for (char c : target) {
            freq[c]++;
        }

        unordered_map<char, int> sFreq;
        for (char c : s) {
            sFreq[c]++;
        }

        int minPossible = INT_MAX;
        for (auto [c, count] : freq) {
            if (sFreq.count(c) == 0) return 0;
            minPossible = min(minPossible, sFreq[c] / count);
        }

        return minPossible;
    }
};
