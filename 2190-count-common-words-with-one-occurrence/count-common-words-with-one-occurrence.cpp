class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        unordered_map<string,int>umap;
        set<string>st;
        for(auto a:words1)
        {
            umap[a]++;
            st.insert(a);
          
        }
        for(auto b:words2)
        {
            umap[b]++;

        }
        int ans =0;
        for(int i=0;i<words2.size();i++)
        {
            if(st.find(words2[i]) !=st.end())
            {
                if(umap[words2[i]] == 2)ans++;
            }
        }
return ans;

        
    }
};