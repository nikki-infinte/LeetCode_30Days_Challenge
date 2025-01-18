class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        //optimal solution 

        int psum=0;
        unordered_map<int,int>umap;
        umap[0]=1;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            psum+=nums[i];
            int x=psum-k;

            if(umap.find(x)!=umap.end())
            {
                cnt+=umap[x];
            }
            umap[psum]++;
        }

        return cnt;
    }
};