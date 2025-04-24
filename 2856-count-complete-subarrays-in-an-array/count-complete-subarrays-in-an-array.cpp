class Solution {
public:
    int DistinctArray(vector<int>&arr)
    {
        unordered_map<int,int>umap;
        for(auto a:arr)
        {
            umap[a]++;
        }
        return umap.size();
    }
    int countCompleteSubarrays(vector<int>& nums) {
        

        //step 1: determine number of distinct element in number 
        int wholeDist = DistinctArray(nums);
        
        //step 2 : shorten problem to subarray of with k distinct number 
        unordered_map<int,int>umap;
        int i=0,j=0;
        int n = nums.size();
        int cnt=0;
        while( j < n)
        {
            umap[nums[j]]++;
            while( i <= j && umap.size() == wholeDist)
            {
                cnt += (n - j); 
                umap[nums[i]]--;
                if(umap[nums[i]] == 0)
                {
                    umap.erase(nums[i]);
                }
                i++;
            }
            
            j++;
        }
        return cnt;
    }
};