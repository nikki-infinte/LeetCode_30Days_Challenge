class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>>umap;
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            umap[s].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto a:umap)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};