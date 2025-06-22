class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n=s2.size();
        int countRe = s1.size();
        unordered_map<char,int>umap;
        for(auto a: s1)
        {
            umap[a]++;
        }
        int i=0,j=0;
        while( j < n)
        {

            char ch = s2[j];
            if(umap[ch] > 0)
            {
                countRe--;
            }
            umap[ch]--;
            j++;
            
            //check wondow size
            if(j-i == s1.size()){
                if(countRe == 0)return true;

                char leftchar = s2[i];
                umap[leftchar]++;
                if(umap[leftchar] > 0)countRe++;
                i++;
            }
             
        }
        return false;
    }
};