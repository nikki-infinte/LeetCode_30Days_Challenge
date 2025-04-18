class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>umap;

        for(auto a:s)
        {
            umap[a]++;
        }
        int even=0 ;
        bool odd=false;
   
        for(auto a:umap)
        {
            if(a.second % 2 ==0){
                even+= a.second;
                
            }else{
                even +=(a.second -1);
                odd = true;
            }
        }
        if(odd)
        {
            even++;
        }

    return even;
        
    }
};