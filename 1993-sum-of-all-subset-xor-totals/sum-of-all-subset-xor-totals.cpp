class Solution {
public:

    void generateSubset(vector<int>&nums,int indx,vector<vector<int>>&res,vector<int>tmp)
    {
        if(indx >= nums.size())
        {
            res.push_back(tmp);
            return ;
        }

        tmp.push_back(nums[indx]);
        generateSubset(nums,indx+1,res,tmp);

        tmp.pop_back();
        generateSubset(nums,indx+1,res,tmp);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>tmp;
        generateSubset(nums,0,res,tmp);

        int ans = 0;
        
    for (int i = 0; i < res.size(); i++) { // iterate over all subsets
        int subsetXor = 0;
        for (int j = 0; j < res[i].size(); j++) {
            subsetXor ^= res[i][j]; // XOR each element of the subset
        }
        ans += subsetXor;
    }
        return ans;
    }
};