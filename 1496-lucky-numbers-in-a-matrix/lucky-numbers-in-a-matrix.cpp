class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
      int n = matrix.size();
    int m = matrix[0].size();

    vector<int> minRow(n, INT_MAX); // to store the min elements of each row
    vector<int> maxCol(m, INT_MIN); // to store the max elements of each column

    // Find the minimum value in each row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < minRow[i]) {
                minRow[i] = matrix[i][j];
            }
        }
    }

    // Find the maximum value in each column
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] > maxCol[j]) {
                maxCol[j] = matrix[i][j];
            }
        }
    }

    // Find all lucky numbers
    vector<int> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                result.push_back(matrix[i][j]);
            }
        }
    }
return result;
        
    }
};