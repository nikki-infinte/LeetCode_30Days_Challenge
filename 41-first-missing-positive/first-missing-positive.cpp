class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_map<int,int>umap;
        int neg=0;
        for(auto a:nums)
        {
            umap[a]++;
            if(a<0)neg++;
        }

        if(neg == nums.size()) {
            return 1;
        }
        int m = *max_element(nums.begin(),nums.end());
        

        for(int i=1;i<=m;i++)
        {
            if(umap.find(i)==umap.end())
            {
                return i;
            }
        }
        return m+1;
    }
};