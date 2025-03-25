class Solution {
public:
    void Generate( vector<int>&nums ,int indx , set<vector<int>>&vec)
    {
        if(indx >= nums.size() )
        {
            vec.insert(nums);
            return ;
        }


        for(int i=indx ;i<nums.size();i++)
        {
            swap(nums[i],nums[indx]);
            Generate(nums,indx+1,vec);
            swap(nums[i],nums[indx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>vec;
        Generate(nums,0,vec);
        vector<vector<int>>ans;

        for(auto a:vec)
        {
            ans.push_back(a);
        }
        return ans;

    }
};