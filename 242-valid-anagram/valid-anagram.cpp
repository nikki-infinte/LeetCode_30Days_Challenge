class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
        }
         
        for(char c:t)
        {
            if (mp.find(c) != mp.end()) {
                mp[c]--;
                // If the count goes below zero, t has extra characters
                if (mp[c] < 0) {
                    return false;
                }
            }else{
                return false;
            }
        }

         for (const auto& pair : mp) {
        if (pair.second != 0) {
            return false;
        }
    }
        return true;
    }
};