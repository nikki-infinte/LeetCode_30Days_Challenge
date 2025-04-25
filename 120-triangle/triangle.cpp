class Solution {
public:


    int function (int i,int j ,vector<vector<int>>&triangle,vector<vector<int>>&dp)
    {
        //base case
        if( i == triangle.size()-1)return triangle[i][j];
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        //recursive relation
        int down = triangle[i][j] + function(i+1,j,triangle,dp);
        int diagonal =triangle[i][j] + function(i+1,j+1,triangle,dp);

        return dp[i][j]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return function(0,0,triangle,dp);

    }
};