class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        

        int cs=0;
        int ans=0;
        unordered_map<int,int>umap;
        umap[0]=1;


        for(int i=0;i<nums.size();i++)
        {
            cs+=nums[i];
            if(umap.find(cs - k)!=umap.end())
            {
                ans+=umap[cs-k];
            }
            umap[cs]++;
        }
     
        return ans;
    }
};