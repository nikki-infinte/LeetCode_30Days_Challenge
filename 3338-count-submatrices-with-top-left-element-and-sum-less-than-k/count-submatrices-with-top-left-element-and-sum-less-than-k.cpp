class Solution {
public:
int n,m;

  
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int cnt =0;

        vector<vector<int>> prefix(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j= 0;j<m;j++)
            {
              prefix[i][j] =grid[i][j];
              if(i > 0) prefix[i][j] +=prefix[i-1][j];
              if(j > 0) prefix[i][j] +=prefix[i][j-1];

              if( i > 0 && j > 0)prefix[i][j] -=prefix[i-1][j-1];
              if(prefix[i][j] <= k)cnt++;
            }
        }

        return cnt;
           
    }
};