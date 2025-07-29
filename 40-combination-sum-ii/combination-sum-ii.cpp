class Solution {
public:

    void solve(vector<vector<int>>&ans,vector<int>&curr,int target,int indx,vector<int>&nums){
        if(target < 0)return ;
        if(target == 0){
                ans.push_back(curr);
                return ;
            }
 
        for(int i=indx;i<nums.size();i++){
            if(i>indx && nums[i-1] == nums[i]){
                continue;
            }
              if(nums[i] > target) break; 
            curr.push_back(nums[i]);
            solve(ans,curr,target-nums[i],i+1,nums);
            curr.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        solve(ans,curr,target,0,nums);
        return ans;
    }
};