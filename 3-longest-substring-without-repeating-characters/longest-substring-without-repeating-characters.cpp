class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     int i=0;
     int j=0;
     int n=s.length();
     unordered_map<char,int>mp;
     int len=0;
     while(j<s.length())
     {
        mp[s[j]]++;
        while(mp.size() < j-i+1)
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
            {
                mp.erase(s[i]);
            }
            i++;
        }
        if(mp.size()==j-i+1)
        {
            len=max(len,j-i+1);

        }

        j++;

     }
    return len;
    }
};