class Solution {
public:

    void backtrack(vector<int>&tmp,vector<vector<int>>&ans , int i,int k,int n)
    {
        if( k ==0 ){
            ans.push_back(tmp);
            return ;
        }

    for(int x = i ;x <= n;x++){
        tmp.push_back(x);
        backtrack(tmp,ans,x+1,k-1,n);
        tmp.pop_back();

    }
        

    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>tmp;
        vector<vector<int>>ans;
        backtrack(tmp,ans,1,k,n);
        return ans;
    }
};