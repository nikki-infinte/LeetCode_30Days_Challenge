class Solution {
public:
    int n,m;
    vector<vector<int>>result;
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(vector<vector<int>>& land,int i,int j,int &r2,int &c2)
    {
        land[i][j]=0;
        r2=max(r2,i);
        c2=max(c2,j);

        for(auto dir:directions)
        {
            int new_i=i+dir[0];
            int new_j=j+dir[1];

            if(new_i >=0 && new_i <n && new_j >=0 && new_j <m &&land[new_i][new_j]==1)
            {
                dfs(land,new_i,new_j,r2,c2);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
      
        n=land.size();
        m=land[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j]==1)
                {
                    // cor.push_back(i);
                    // cor.push_back(j);
                    int r1=i;
                    int c1=j;
                    int r2=i;
                    int c2=j;
                    dfs(land,i,j,r2,c2);
                    result.push_back({r1,c1,r2,c2});
                }
            }
        }
          return result;
    }
  
};