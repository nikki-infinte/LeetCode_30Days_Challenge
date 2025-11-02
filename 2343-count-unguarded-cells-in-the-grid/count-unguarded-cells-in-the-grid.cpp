class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>>grid(m,vector<int>(n,0));
        // 0 = empty 1 = guard 2 = wall 3 =guarded
        for(auto &g :guards){
            grid[g[0]][g[1]] = 1;
        }
        for(auto &w : walls){
            grid[w[0]][w[1]] = 2;
        }

        vector<int>dx = {1,-1,0,0};
        vector<int>dy ={0,0,1,-1};

 int count =0;
        for(auto &g:guards ){
            int x = g[0],y=g[1];

            for(int k=0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];

                while( nx >=0 && ny>=0 && nx <m && ny < n && grid[nx][ny] !=1 && grid[nx][ny] !=2){
                    if(grid[nx][ny] == 0){
                        grid[nx][ny] = 3;
                        
                    }
                    nx+=dx[k];
                        ny+=dy[k];
                }
            }
        }
         for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j] == 0)count++;
                }
            }
        return count;
    }
};