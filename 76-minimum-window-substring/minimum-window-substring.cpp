class Solution {
public:
    string minWindow(string s, string t) {
        int n = t.size();
        int reqCount = n;
        unordered_map<char,int>mp;
        for(auto a:t){
            mp[a]++;
        }

        int m = s.length();
        int i=0,j=0;
        int minLen =INT_MAX;
        int start_i = -1;
        while(j<m){
            if(mp[s[j]] > 0)reqCount--;
            mp[s[j]]--;

            while(reqCount == 0){
                if(j-i+1 <minLen){
                    start_i = i;
                    minLen = j-i+1;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    reqCount++;
                }
                i++;
            }
            j++;
        }
        return (minLen == INT_MAX) ? "" : s.substr(start_i,minLen);
    }

};