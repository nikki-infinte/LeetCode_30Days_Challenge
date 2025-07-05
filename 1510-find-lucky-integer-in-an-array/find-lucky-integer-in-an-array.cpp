class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>umap;
        for(auto a:arr){
            umap[a]++;
        }

        int ans =-1;
        for(auto a:umap){
            if(a.second == a.first){
                ans = max(ans ,a.first);
            }
        }
        return ans;
    }
};