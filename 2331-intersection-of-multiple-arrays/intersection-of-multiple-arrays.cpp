class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        
        unordered_map<int,int>umap;
        for(auto a:nums){
            for(int i=0;i<a.size();i++){
                umap[a[i]]++;
            }
        }

     
        vector<int>ans;

        for(auto a:umap){
            if(a.second == nums.size()){
                ans.push_back(a.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};