class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i=0,j=0;
        int n = s.length();
        int maxlen = 0;
        unordered_map<char,int>umap;
        while( j < n )
        {
            
            umap[s[j]] ++ ;
            while(umap[s[j]] > 1 && i<j)
            {
               
                umap[s[i]]--;
                i++;
            }

            maxlen = max(j-i+1 , maxlen);
            j++;
        }
        return maxlen;
    }
};