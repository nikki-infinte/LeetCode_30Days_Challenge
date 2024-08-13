class Solution {
public:
    void solve(vector<int>&curr,vector<int>& candidates,int target,int indx,vector<vector<int>>&res)
    {
        if(target <0){
            return ;
        }
        if(target==0)
        {
            res.push_back(curr);
            return;
        }

        for(int i=indx;i<candidates.size();i++)
        {
            if(i >indx && candidates[i] ==candidates[i-1])
            {
                continue;
            }

            //DO step
            curr.push_back(candidates[i]);
            //calculate
            solve(curr,candidates,target-candidates[i],i+1,res);
            //undo step
            curr.pop_back();
           
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int i=0;
        vector<int>curr;
        vector<vector<int>>res;
        sort(candidates.begin(),candidates.end());

        solve(curr,candidates,target,i,res);
        return res;
    }
};