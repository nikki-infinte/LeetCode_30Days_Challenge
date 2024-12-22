class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        //using substring sliding window
        int i=0;
        int j=0;
        unordered_map<char,int>umap;
        int largest=0;
        while(j<s.length())
        {
            umap[s[j]]++;
            while(umap[s[j]] > 1 )
            {
               
                umap[s[i]]--;
                i++;
                 
            }
            largest=max(largest,j-i+1);
            j++;
        }
        
        return largest;
    }
};