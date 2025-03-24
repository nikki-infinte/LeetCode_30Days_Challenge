class Solution {
public:
    int n;
    void Backtrack(vector<int>&candidates , int target, vector<int>&tmp,int indx ,vector<vector<int>>&res){
        if(indx >= n ){
            if(target == 0)
            {
                res.push_back(tmp);
            }
            return ;
        }

       if(target < 0)
            return;
        
        
        Backtrack(candidates,target,tmp,indx+1,res);
        tmp.push_back(candidates[indx]);
        target = target - candidates[indx];
        Backtrack(candidates,target,tmp,indx,res);
        tmp.pop_back();

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        n = candidates.size();
    vector<int>tmp;
        Backtrack(candidates,target,tmp,0,res);
        return res;




    }
};