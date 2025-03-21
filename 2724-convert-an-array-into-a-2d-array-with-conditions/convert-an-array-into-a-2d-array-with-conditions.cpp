class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>umap;

        int n = nums.size();
        int max_row = 0;
        for(int i=0;i<n;i++)
        {
            umap[nums[i]] ++;
            max_row = max(max_row,umap[nums[i]]);
        }

        if(max_row == 1){
          vector<vector<int>>vec1;
          vec1.push_back(nums);
          return vec1;
        }

        vector<vector<int>>vec;

        while(!umap.empty())
        {
            vector<int>v;
            auto it = umap.begin();
            while( it != umap.end())
            {

                v.push_back(it->first);
                if(--(it->second) == 0){
                    it = umap.erase(it);
                }else{
                    ++it;
                }
            }
            vec.push_back(v);
        }
return vec;


    }
};