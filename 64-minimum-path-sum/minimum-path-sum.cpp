class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));  // Track min cost
        queue<pair<int, int>> q;
        
        q.push({0, 0});
        cost[0][0] = grid[0][0];

        vector<int> x_dir = {1, 0};  // Move only down and right
        vector<int> y_dir = {0, 1};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 2; i++) {
                int new_x = x + x_dir[i];
                int new_y = y + y_dir[i];

                if (new_x >= 0 && new_y >= 0 && new_x < n && new_y < m) {
                    int new_cost = cost[x][y] + grid[new_x][new_y];

                    if (new_cost < cost[new_x][new_y]) {  // Only update if new path is better
                        cost[new_x][new_y] = new_cost;
                        q.push({new_x, new_y});
                    }
                }
            }
        }

        return cost[n-1][m-1];  // Minimum path sum to bottom-right corner
    }
};