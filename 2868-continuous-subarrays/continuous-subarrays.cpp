class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        int i=0,j=0;
        map<int,int>umap;
        int  n = nums.size();
        long long count =0;
        while( j < n)
        {
            umap[nums[j]]++;

            while( abs(umap.rbegin()->first - umap.begin()->first) > 2 ){
                umap[nums[i]]--;
                if(umap[nums[i]] == 0)
                {
                    umap.erase(nums[i]);
                }
                i++;
            }
            count+=j-i+1;
            j++;
        }
        return count;
    }
};