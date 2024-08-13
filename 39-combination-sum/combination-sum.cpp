class Solution {
public:
    void Backtrack(vector<int>& curr,vector<vector<int>>&res,vector<int>& candidates,int idx,int target)
    { if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                break; // No need to continue if the candidate is greater than the target
            }
            
            curr.push_back(candidates[i]);
            Backtrack(curr, res, candidates, i, target - candidates[i]); // Use the same element again
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>curr;
        vector<vector<int>>res;
        sort(candidates.begin(), candidates.end());
        Backtrack(curr,res,candidates,0,target);
         
        return res;
    }
};