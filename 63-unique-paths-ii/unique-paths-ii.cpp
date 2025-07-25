class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int n= obstacleGrid.size();
       int m = obstacleGrid[0].size();
        vector<vector<int>>grid(n,vector<int>(m,0));
        

            // Base case: starting cell
        if(obstacleGrid[0][0] == 1) return 0;
        grid[0][0] = 1;


          for(int i = 1; i < n; i++) {
            if(obstacleGrid[i][0] == 1) break;
            grid[i][0] = 1;
        }

        // Fill first row
        for(int j = 1; j < m; j++) {
            if(obstacleGrid[0][j] == 1) break;
            grid[0][j] = 1;
        }

         for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(obstacleGrid[i][j] == 1) {
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                }
            }
        }
        return grid[n-1][m-1];
    }
};