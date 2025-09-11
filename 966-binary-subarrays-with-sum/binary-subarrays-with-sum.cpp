class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int,int>umap;
        int sum =0;
        int n = nums.size();
        umap[0]=1;
        int count = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];

            if(umap.find(sum-goal)!=umap.end()){
                count+=umap[sum-goal];
            }
            umap[sum]++;
        }
        return count;



     
    }
};