class Solution {
public:
    vector<vector<int>>visit;
    int n,m;
    void BFS(vector<vector<char>>& board,int i,int j)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        visit[i][j]=1;
    while(!q.empty()){


        auto [x,y]=q.front();
        q.pop();

        vector<vector<int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        for(int d=0;d<4;d++)
        {
            int newx=x+direction[d][0];
            int newy=y+direction[d][1];
 if (newx >= 0 && newx < n && newy >= 0 && newy < m && board[newx][newy] == 'X' && visit[newx][newy] == 0) {
                q.push({newx,newy});
                visit[newx][newy]=1;
            }
        }
        
        
    }

    }
    int countBattleships(vector<vector<char>>& board) {
        
        int cnt=0;
        n=board.size();
        m=board[0].size();
           visit = vector<vector<int>>(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X'&& visit[i][j]==0)
                {
                    cnt++;
                    BFS(board,i,j);
                }
            }
        }
        return cnt;
    }
};