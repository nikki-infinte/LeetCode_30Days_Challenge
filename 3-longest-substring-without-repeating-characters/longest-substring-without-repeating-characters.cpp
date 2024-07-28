class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int i = 0, j = 0;
        int maxcount = 0;
        unordered_set<char> set;
        
        while (j < s.length()) {
            if (set.find(s[j]) == set.end()) {
                set.insert(s[j]);
                maxcount = max(maxcount, j - i + 1);
                j++;
            } else {
                set.erase(s[i]);
                i++;
            }
        }
        return maxcount;
    

    }
};