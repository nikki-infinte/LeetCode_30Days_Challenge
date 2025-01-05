class Solution {
public:
   queue<pair<int,int>>q;
   void BFS(vector<vector<char>>& grid,int i,int j,int n,int m)
   {
        q.push({i, j});
        grid[i][j] = '0';
    while(!q.empty()){
        int i =q.front().first;
        int j=q.front().second;
        q.pop();
        int row[4] = {1, -1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        for(int k=0;k<4;k++)
        {
            int new_i=i+row[k];
            int new_j=j+col[k];
         

            if(new_i >=0 && new_j>=0 && new_i<n && new_j <m)
            {
                if(grid[new_i][new_j]=='1')
                {
                    q.push(make_pair(new_i,new_j));
                    grid[new_i][new_j]='0';
                }
            }
        }
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
                grid[i][j]='0';
                BFS(grid,i,j,n,m);
                cnt++;
            }
        }
     }
return cnt;


    }
};