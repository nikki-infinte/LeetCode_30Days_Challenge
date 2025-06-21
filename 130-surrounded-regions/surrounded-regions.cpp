class Solution {
public:

    void DFS(int i, int  j, vector<vector<char>>&board,int n,int m)
    {
        board[i][j] = 'B';
        vector<int>dx ={1,-1,0,0};
        vector<int>dy = {0,0,-1,1};
        for(int k=0;k<4;k++)
        {
            int newi = dx[k]+i;
            int newj = dy[k]+j;

            if(newi >=0 && newj >=0 && newi<n && newj <m && board[newi][newj] == 'O'){
                DFS(newi,newj,board,n,m);
            } 
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();


        // top to bottom 
        for(int i=0;i < n;i++ )
        {
            //for 0th column 
            if(board[i][0] == 'O')
            {
                DFS(i,0,board,n,m);
            }

            if(board[i][m-1] == 'O'){
                DFS(i,m-1,board,n,m);
            }
        }


        //left to right
        for(int l = 0 ;l < m ;l++ )
        {
            if(board[0][l] == 'O')
            {
                 DFS(0,l,board,n,m);
            }


            if(board[n-1][l] == 'O')
            {
                DFS(n-1,l,board,n,m);
            }
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'B'){
                    board[i][j]= 'O';
                }
            }
        }


    }
};