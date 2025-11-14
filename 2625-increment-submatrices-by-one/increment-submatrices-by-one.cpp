class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>>board(n,vector<int>(n,0));
        for(auto elem:queries){
            vector<int>e = elem;
            int r1 = elem[0];
            int c1 = elem[1];
            int r2 = elem[2];
            int c2 = elem[3];

            for(int i=r1;i<=r2;i++){
                for(int j=c1;j<=c2;j++){

                    board[i][j]+=1;
                }
            }
        }   
        return board;
    }
};