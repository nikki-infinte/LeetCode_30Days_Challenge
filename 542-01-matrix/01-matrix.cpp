class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,false));
        vector<vector<int>>dist(n,vector<int>(m,0));

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 0){
                    q.push({i,j});
                    visit[i][j]=true;
                }
            }
        }

        while(!q.empty())
        {
            pair<int,int>p = q.front();
            q.pop();

            int dx[] = {1,0,-1,0};
            int dy[] = {0,-1,0,1};

            for(int i=0;i<4;i++)
            {
                int newx = dx[i]+p.first;
                int newy = dy[i]+p.second;

                if(newx >= 0 && newy >= 0 && newx < n && newy < m  && visit[newx][newy] == false){
                    dist[newx][newy] = dist[p.first][p.second]+1;
                    visit[newx][newy] = true;

                    q.push({newx,newy});
                }
            }
        }
    return dist;


    }
};