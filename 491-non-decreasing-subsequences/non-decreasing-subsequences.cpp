class Solution {
public:

    void solve(set<vector<int>>&ans , vector<int>tmp, int indx,vector<int>&nums){

        if( indx >= nums.size() ){
            if(tmp.size()>= 2){
                ans.insert(tmp);
            }
            return ;
        }

        if(tmp.empty() || tmp.back() <= nums[indx]){
            tmp.push_back(nums[indx]);
            solve(ans,tmp,indx+1,nums);
            tmp.pop_back();
        }
         solve(ans,tmp,indx+1,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>ans;
        vector<int>tmp;
        solve(ans,tmp,0,nums);

        vector<vector<int>>ans2;
        for(auto s:ans){
            ans2.push_back(s);
        }
        return ans2;

    }
};