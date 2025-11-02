class Solution {
public:
int N;
bool safe(vector<string>board,int r,int c){
    //upward left diagonal
    int i=r,j=c;
    i-=1;
    j-=1;
    while(i >=0 && j>=0 && board[i][j] == '.'){
        i--;
        j--;
    }
    if(i >=0 && j>=0 && board[i][j] == 'Q')return false;

    //upward right diagonal
    i=r,j=c;
    i-=1;
    j+=1;
    while(i>=0 && j<N&& board[i][j] == '.'){
        i--;
        j++;
    }
    if(i>=0 && j<N && board[i][j]=='Q')return false;


    //upward directions
    i=r,j=c;
    while(i>=0&& board[i][j]=='.'){
        i--;
    }
    if(i>=0&& board[i][j]=='Q')return false;

    return true;
}
    void solve(vector<string>&board,int row,vector<vector<string>>&ans){

        if(row == N){
            ans.push_back(board);
            return ;
        }

        for(int i=0;i<N;i++){

            if(safe(board,row,i)){
                board[row][i]='Q';
                solve(board,row+1,ans);
                board[row][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        N =n;
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        solve(board,0,ans);
        return ans;
    }
};