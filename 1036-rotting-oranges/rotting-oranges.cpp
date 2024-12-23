class Solution {
public:
    int n,m;

    int orangesRotting(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }else if(grid[i][j]==1)fresh++;
            }
        }

        if(fresh==0)return 0;

        //bfs
      int time=0;
       int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty())
        {

            int size=q.size();
            bool rottedThisMin=false;
            for(int i=0;i<size;i++)
          { 
            auto [x,y]=q.front();
            q.pop();
            
            for(int d=0;d<4;d++)
            {
                int newx=x+directions[d][0];
                int newy=y+directions[d][1];

                //check bounds and if orange can be rotted

                if(newx >=0 && newx<n && newy>=0 && newy <m && grid[newx][newy]==1)
                {
                    grid[newx][newy]=2;
                    q.push({newx,newy});
                    fresh--;
                    rottedThisMin=true;
                }
            }

        
          }
            if(rottedThisMin)time++;
        }

        //unreached
          for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
       return time;
    }
};