class Solution {
public:
    bool rec(int i, int j, int m, int n, int ind, vector<vector<char>>& board, string& word, vector<vector<bool>>& visited) {
        if (ind == word.size()) return true;

        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[ind]) 
            return false;

        visited[i][j] = true;

        bool down = rec(i + 1, j, m, n, ind + 1, board, word, visited);
        bool up = rec(i - 1, j, m, n, ind + 1, board, word, visited);
        bool left = rec(i, j - 1, m, n, ind + 1, board, word, visited);
        bool right = rec(i, j + 1, m, n, ind + 1, board, word, visited);

        visited[i][j] = false; // Backtrack

        return down || up || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Initialize visited matrix
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (rec(i, j, m, n, 0, board, word, visited)) 
                        return true;
                }
            }
        }

        return false;
    }
};
