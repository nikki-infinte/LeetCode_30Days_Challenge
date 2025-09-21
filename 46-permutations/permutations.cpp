class Solution {
public:
    int n ;
    void solve(int indx, vector<int>&tmp,vector<vector<int>>&ans){

        //base case 
        if(indx >= n){
            ans.push_back(tmp);
            return ;
        }

        for(int j=indx;j<n;j++){
            swap(tmp[j],tmp[indx]);
            solve(indx+1,tmp,ans);
            swap(tmp[j],tmp[indx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>>ans;
        vector<int>tmp=nums;
        solve(0,tmp,ans);
        return ans;
    }
};