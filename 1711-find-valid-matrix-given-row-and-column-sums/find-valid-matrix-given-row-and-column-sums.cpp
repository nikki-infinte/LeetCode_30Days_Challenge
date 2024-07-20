class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
     int n = rowSum.size();
        int m = colSum.size();
        int i = 0, j = 0;
        vector<vector<int>> vec(n, vector<int>(m, 0));
        
        while (i < n && j < m) {
            vec[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= vec[i][j];
            colSum[j] -= vec[i][j];
            
            if (rowSum[i] == 0) {
                i++;
            }
            if (colSum[j] == 0) {
                j++;
            }
        }
        
        return vec;
    
    }
};