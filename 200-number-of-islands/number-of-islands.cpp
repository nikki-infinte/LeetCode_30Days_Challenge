class Solution {
public:
    bool isValid(vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1')
        {
            return true;
        }
        return false;
    }

    void numberOfIs(vector<vector<char>>& grid,int i,int j,int n,int m)
    {
        grid[i][j]='0';
        if(isValid(grid,i+1,j,n,m))
        {
            numberOfIs(grid,i+1,j,n,m);
        }
          if(isValid(grid,i,j+1,n,m))
        {
            numberOfIs(grid,i,j+1,n,m);
        }
          if(isValid(grid,i-1,j,n,m))
        {
            numberOfIs(grid,i-1,j,n,m);
        }
          if(isValid(grid,i,j-1,n,m))
        {
            numberOfIs(grid,i,j-1,n,m);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    numberOfIs(grid,i,j,n,m);
                }
            }
        }
        return cnt;
    }
};