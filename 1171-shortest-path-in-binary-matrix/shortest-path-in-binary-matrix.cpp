class Solution {
public:

    // thought of using BFS with 8 direction 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dx = {-1, -1, -1,  0, 0, 1, 1, 1};
vector<int> dy = {-1,  0,  1, -1, 1, -1, 0, 1};
        if(grid[0][0] == 1)return -1;

        q.push({0,0});
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0] = true;
        int cost=1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--){
                pair<int,int>xy = q.front();
                q.pop();

                if(xy.first == n-1 && xy.second == m-1){
                    return cost;
                }
                for(int i=0;i<8;i++){
                    int newx = xy.first+dx[i];
                    int newy = xy.second+dy[i];

                    if(newx >=0 && newy >=0 && newx < n && newy < m && grid[newx][newy] == 0 && !visited[newx][newy] ){
                        q.push({newx,newy});
                        visited[newx][newy] = true;
                    }
                }
            }
             cost++;
        }

        return -1;
    }
};