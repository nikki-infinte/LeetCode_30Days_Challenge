class Solution {
public:

    
    vector<int> targetIndices(vector<int>& nums, int target) {
       
       vector<int>ans;
       sort(nums.begin(),nums.end());
       
       int left=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
       int right=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
       if(left <right)
       {
        for(int i=left;i<right;i++)
        {
            ans.push_back(i);
        }
       }
       return ans;

       
       
    }
};