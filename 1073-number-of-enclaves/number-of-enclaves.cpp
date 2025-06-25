class Solution {
public:
    int m,n;
    void DFS(vector<vector<int>>& grid, int i,int j)
    {
        grid[i][j] = 2;
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,-1,1};


        for(int k=0;k<4;k++)
        {
            int newx = dx[k]+i;
            int newy = dy[k]+j;

            if(newx >=0 && newy >= 0 && newx < n && newy < m && grid[newx][newy] == 1  ){
                DFS(grid,newx,newy);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();

        // First and last column
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) {
                DFS(grid, i, 0);
            }
            if(grid[i][m - 1] == 1) {
                DFS(grid, i, m - 1);
            }
        }

        // First and last row
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1) {
                DFS(grid, 0, j);
            }
            if(grid[n - 1][j] == 1) {
                DFS(grid, n - 1, j);
            }
        }
        int cnt= 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)cnt++;
            }
        }
        return cnt;
    }
};