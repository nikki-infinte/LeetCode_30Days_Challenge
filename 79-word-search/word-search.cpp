class Solution {
public:
int n,m;
    vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
    bool searchWord(vector<vector<char>>& board,int i,int j,int inx,string& word)
    {
        if(inx==word.size())
        {
            return true;
        }

        if(i<0 || j<0 || i >= n|| j >= m ||board[i][j]=='$' || board[i][j] !=word[inx])
        {
            return false;
        }

        char temp=board[i][j];
        board[i][j]='$';

        for(auto& d:direction)
        {
            int new_i=i+d[0];
            int new_j=j+d[1];
        
        if(searchWord(board,new_i,new_j,inx+1,word)){
            return true;
        }
        }
        board[i][j]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         n=board.size();
         m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && searchWord(board,i,j,0,word))
                {
                    return true;
                }
            }
        }
        return false;
    }
};