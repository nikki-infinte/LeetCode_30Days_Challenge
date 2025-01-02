class Solution {
public:
 vector<vector<int>>ans;
   void unclear(vector<int>&nums,int index)
   {
    if(index==nums.size())
    {
        ans.push_back(nums);
        return ;
    }

        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            unclear(nums,index+1);
            swap(nums[index],nums[i]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
       unclear(nums,0);
       return ans;
    }
};