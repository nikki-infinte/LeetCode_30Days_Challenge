class Solution {
public:
    int MOD = 1e9 + 7;

    int DFS(int m, int n, int i, int j, int maxMove, vector<vector<vector<int>>>& dp) {
        // Out of bounds: valid path
        if (i < 0 || j < 0 || i >= m || j >= n) return 1;
        // No more moves left: invalid path
        if (maxMove == 0) return 0;

        // Memoization check
        if (dp[i][j][maxMove] != -1) return dp[i][j][maxMove];

        int count = 0;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int k = 0; k < 4; k++) {
            int newx = i + dx[k];
            int newy = j + dy[k];
            count = (count + DFS(m, n, newx, newy, maxMove - 1, dp)) % MOD;
        }

        return dp[i][j][maxMove] = count;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return DFS(m, n, startRow, startColumn, maxMove, dp);
    }
};
