class Solution {
public:
    int n,m;
    void dfs(vector<vector<char>>& grid,int i,int j)
    { if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] != '1') {
            return;
        }


        grid[i][j] = '$';

        // Explore all four possible directions
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int islands=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};