class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        unordered_map<string,int>umap;
        unordered_map<string,int>umap2;

        for(auto a:words1)
        {
            umap[a]++;
        }

        for(auto b:words2)
        {
            umap2[b]++;
        }
       
       int ans = 0;
        for (auto& [word, count] : umap) {
            if (count == 1 && umap2[word] == 1) {
                ans++;
            }
        }
        return ans;



    }
};