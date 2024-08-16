class Solution {
public:
    int characterReplacement(string s, int k) {
        
        //using sliding window and map
        unordered_map<char,int>mp;
        int i=0;
        int j=0;
        int max_freq=0;
        int ans=0;
        while(j<s.length())
        {
            //calculations
            mp[s[j]]++;
            max_freq=max(max_freq,mp[s[j]]);
            //condition to replace 
           
           if((j-i+1)-max_freq > k)
           {
            mp[s[i]]--;
            if(mp[s[i]]==0)
            {
                mp.erase(s[i]);
            }
            i++;
           }

            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
        
    }
};