class Solution {
public:


    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int i = 0; i < m; i++) {
            dp[n - 1][i] = matrix[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int down = dp[i + 1][j];
                int Left = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int right = (j < m - 1) ? dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(down,min( Left, right));
            }
        }
        int result = INT_MAX;
        for (int j = 0; j < m; ++j) {
            result = min(result, dp[0][j]);
        }
        return result;
    }
};
