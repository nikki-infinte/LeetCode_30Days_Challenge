class Solution {
public:
    bool isDistinct(vector<int>&nums)
    {
        unordered_map<int,int>umap;
        for(auto a:nums)
        {
            if(umap[a]>0)return false;
            umap[a]++;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(umap[i] >1)
            {
                return false;
            }
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) 
    {
        int op=0;
        while(!isDistinct(nums))
        {
            if(nums.size() < 3 && !isDistinct(nums))
            {
                op++;
               break;
            }else{
            //remove first 3 element 
                 nums.erase(nums.begin(), nums.begin() + 3);
                op++;
            }
            
            
        }
        return op;
        
    }
};