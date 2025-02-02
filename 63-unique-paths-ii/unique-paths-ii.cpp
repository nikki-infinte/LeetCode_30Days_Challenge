class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        

        int r =grid.size(),c=grid[0].size();

        vector<vector<int>>dp ( r,vector<int>(c,0));
        if(grid[0][0] == 0)
        {
            dp[0][0]=1;
        }

          for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
          
            // If cell has an obstacle, set paths to 0
            if(grid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
              
                // Accumulate paths from top cell
                if(i > 0) dp[i][j] += dp[i-1][j];
              
                // Accumulate paths from left cell
                if(j > 0) dp[i][j] += dp[i][j-1];
            }
        }
    }
    return dp[r-1][c-1];
    }
};