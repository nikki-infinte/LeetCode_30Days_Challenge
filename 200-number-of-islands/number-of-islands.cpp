class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<char>>& grid) {
    if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1') {
        return true;
    }
    return false;
    }

    void DFS(int i, int j, int n, int m, vector<vector<char>>& grid) {
    grid[i][j] = '0'; // Update the cell to '0' to mark it as visited
    if (isValid(i + 1, j, n, m, grid)) {
        DFS(i + 1, j, n, m, grid);
    }
    if (isValid(i - 1, j, n, m, grid)) {
        DFS(i - 1, j, n, m, grid);
    }
    if (isValid(i, j + 1, n, m, grid)) {
        DFS(i, j + 1, n, m, grid);
    }
    if (isValid(i, j - 1, n, m, grid)) {
        DFS(i, j - 1, n, m, grid);
    }
}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    DFS(i,j,n,m,grid);
                }
            }
        }
        return count;
    }
};