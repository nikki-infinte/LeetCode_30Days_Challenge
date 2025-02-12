class Solution {
public:


    void gray(int n,vector<int>&ans)
    {
        if( n== 1)
        {
            ans.push_back(0);
            ans.push_back(1);
            return ;
        }

        gray(n-1,ans);
        int i=ans.size()-1;
        while(i>=0)
        {
            int val = ans[i] | 1<<(n-1);
            ans.push_back(val);
            i--;
        }

    }
    vector<int> grayCode(int n) {
        
        vector<int>ans;
        gray(n,ans);
        return ans;

    }
};