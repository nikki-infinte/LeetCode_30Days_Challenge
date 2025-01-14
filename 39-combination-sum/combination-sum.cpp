class Solution {
public:
     vector<vector<int>>ans;
    void backtrack(int target,int curr,vector<int>tmp,vector<int>& candidates,int indx)
    {
        if(curr>target)
        {
            return ;
        }

        if(curr==target)
        {
            ans.push_back(tmp);
            return ;
        }
        for(int i=indx;i<candidates.size();i++)
        {
            //include
            tmp.push_back(candidates[i]);
            curr+=candidates[i];
            backtrack(target,curr,tmp,candidates,i);
            //exclude
            tmp.pop_back();
            curr-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>tmp;
        backtrack(target,0,tmp,candidates,0);
        return ans;
    }
};