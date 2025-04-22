class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        if(nums.size() < 2)return false;
        int n = nums.size();
        unordered_map<int,int>umap;
        umap[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
           sum+=nums[i];
            int rem = sum % k;
            if(umap.find(rem)!=umap.end())
            {
               if (i - umap[rem] >= 2) return true;
            }else{
                umap[rem]=i;
            }
            
        }
        return false;
    }
};