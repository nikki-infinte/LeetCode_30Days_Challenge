class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int n= nums.size();

        int sum =0,maxlen = 0;
        
        int i=0;
        unordered_map<int,int>umap;
        umap[0]=-1;
        while(i<n)
        {
            sum += (nums[i] == 0)? -1:1;
            if(umap.find(sum)!=umap.end())
            {
               maxlen = max(i - umap[sum], maxlen);
            }else{
                umap[sum]=i;
            }
            i++;
        }
        return maxlen;
       
    }
};