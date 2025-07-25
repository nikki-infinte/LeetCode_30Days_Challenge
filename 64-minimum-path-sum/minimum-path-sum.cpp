class Solution {
public:
    int n , m;
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if( i >=n || j >=m)return INT_MAX;
        if( i== n-1 && j==m-1){
            return dp[i][j]=grid[i][j];
        }
        if(dp[i][j] != -1)return dp[i][j]; 
        int takeRight = solve(i,j+1,grid,dp);
        int takeDown = solve(i+1,j,grid,dp);
        return dp[i][j] = grid[i][j]+min(takeRight,takeDown);
    }
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return solve(0,0,grid,dp);

    }
};