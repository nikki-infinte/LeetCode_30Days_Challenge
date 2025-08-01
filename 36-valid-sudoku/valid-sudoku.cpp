class Solution {
public:
    bool traverse(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
         unordered_set<int> st;
        for (int i = sr; i <= er; i++) {
           
            for (int j = sc; j <= ec; j++) {
                if (board[i][j] == '.')
                    continue;

                if (st.find(board[i][j]) != st.end()) {
                    return false;
                } else {
                    st.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int row = 0; row < 9; row++) {
            unordered_set<int> st;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;

                if (st.find(board[row][col]) != st.end())
                    return false;
                else
                    st.insert(board[row][col]);
            }
        }

        for (int col = 0; col < 9; col++) {
            unordered_set<int> st;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.')
                    continue;

                if (st.find(board[row][col]) != st.end())
                    return false;
                else
                    st.insert(board[row][col]);
            }
        }

        for (int sr = 0; sr < 9; sr += 3) {
            int er = sr + 2;
            for (int sc = 0; sc < 9; sc += 3) {
                int ec = sc + 2;
                if (traverse(board, sr, er, sc, ec) == false)
                    return false;
            }
        }

        return true;
    }
};