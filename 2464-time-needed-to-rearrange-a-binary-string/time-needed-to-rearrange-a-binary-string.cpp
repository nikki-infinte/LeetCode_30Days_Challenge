class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int count = 0;
        bool change = true;
        while (change) {

            int n = s.size();
            string next = s;
            change = false;
            for (int i = 0; i < s.size() - 1; ++i) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    next[i] = '1';
                    next[i + 1] = '0';
                    ++i;
                    change = true;
                }
            }

            if (change) {
                s = next;
                ++count;
            }
        }
        return count;
    }
};