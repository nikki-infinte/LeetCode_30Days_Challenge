class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = 8;
        int rookRow = 0, rookCol = 0;

        // Step 1: Find the position of the Rook
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'R') {
                    rookRow = i;
                    rookCol = j;
                    break;
                }
            }
        }

        int cnt = 0;

        // Move Up
        for (int i = rookRow - 1; i >= 0; i--) {
            if (board[i][rookCol] == 'B') break;
            if (board[i][rookCol] == 'p') {
                cnt++;
                break;
            }
        }

        // Move Down
        for (int i = rookRow + 1; i < n; i++) {
            if (board[i][rookCol] == 'B') break;
            if (board[i][rookCol] == 'p') {
                cnt++;
                break;
            }
        }

        // Move Left
        for (int j = rookCol - 1; j >= 0; j--) {
            if (board[rookRow][j] == 'B') break;
            if (board[rookRow][j] == 'p') {
                cnt++;
                break;
            }
        }

        // Move Right
        for (int j = rookCol + 1; j < n; j++) {
            if (board[rookRow][j] == 'B') break;
            if (board[rookRow][j] == 'p') {
                cnt++;
                break;
            }
        }

        return cnt;
    }
};
