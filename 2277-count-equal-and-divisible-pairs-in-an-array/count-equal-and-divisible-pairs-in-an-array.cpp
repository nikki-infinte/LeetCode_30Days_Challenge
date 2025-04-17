class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        
        int n = nums.size();
        int cnt =0;
        unordered_map<int,vector<int>>umap;

        for(int i=0;i<n;i++)
        {
            umap[nums[i]].push_back(i);
        }

        for(auto x: umap)
        {
          
                vector<int>&indices  = x.second;
                int s= indices.size();

                for(int l=0;l<s ;l++)
                {
                    for(int p=l+1;p<s;p++)
                    {
                        if((indices[l]*indices[p])% k ==0)
                        {
                            cnt++;
                        }
                    }
                }
            
        }

        return cnt;
    }
};