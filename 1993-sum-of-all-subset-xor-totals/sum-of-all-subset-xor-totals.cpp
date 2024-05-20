class Solution {
public:

    void AllPossibleSubset(vector<int>nums,vector<int>curr,vector<vector<int>>&ans,int i)
    {
        if(i==nums.size())
        {
            ans.push_back(curr);
            return ;
        }
        curr.push_back(nums[i]);
        AllPossibleSubset(nums,curr,ans,i+1);
        curr.pop_back();
        AllPossibleSubset(nums,curr,ans,i+1);


    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>curr;
        AllPossibleSubset(nums,curr,ans,0);

        int res=0;
        for(vector<int> subset:ans)
        {
            int Xor=0;
            for(int a:subset)
            {
                Xor^=a;
            }
            res+=Xor;
        }
        return res;
    }
};