class Solution {
public:
    char findTheDifference(string s, string t) {
        
     unordered_map<char,int>umap;
     for(auto a:s)
     {
        umap[a]++;
     }
        for(int i=0;i<t.size();i++)
        {
            if(umap.find(t[i]) != umap.end())
            {
                if(umap[t[i]] == 0) return t[i];
                else umap[t[i]]--;
            }else return t[i];
        }
        return ' ';
    }
    
};