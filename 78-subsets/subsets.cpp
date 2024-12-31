class Solution {
public:
    void backtrack(int index,vector<int>&nums,vector<int>tmp,vector<vector<int>>&ans)
    {
        if(index==nums.size())
        {
            ans.push_back(tmp);
            return;
        }

        
        //exclude
          backtrack(index+1,nums,tmp,ans);
        //include
        tmp.push_back(nums[index]);
        backtrack(index+1,nums,tmp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tmp;
        backtrack(0,nums,tmp,ans);
        return ans;
    }
};