class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();

        queue<pair<int,int>>q;
        int z_cnt=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }else if(grid[i][j]==0)
                {
                    z_cnt++;
                }
            }
        }
        if(z_cnt==n*m)
        {
            return 0;
        }
        int timer=0;
        int row[4]={1,-1,0,0};
        int col[4]={0,0,-1,1};
        while(!q.empty())
        {
            int curr_size=q.size();
            timer++;
            while(curr_size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    int new_i=i+row[k];
                    int new_j=j+col[k];

                   if (new_i >= 0 && new_j >= 0 && new_i < m && new_j < n)
                    {
                        if(grid[new_i][new_j]==1)
                        {
                            q.push(make_pair(new_i,new_j));
                            grid[new_i][new_j]=2;
                        }
                    }
                }

            }


        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return timer-1;
    }
};