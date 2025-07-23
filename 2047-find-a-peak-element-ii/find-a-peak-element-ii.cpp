class Solution {
public:
    int maxElement(vector<vector<int>>& mat, int mid, int m, int n) {

        int maxE = 0;
        for (int i = 1; i < mat.size(); i++) {
            if (mat[i][mid] > mat[maxE][mid]) {
                maxE = i;
            }
        }
        return maxE;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat[0].size() - 1;
        int n = mat.size();
        int m = mat[0].size();

        while (low <= high) {
            int mid = (low + high) / 2;

            int row = maxElement(mat, mid, m, n);
            int left = (mid - 1 >= 0) ? mat[row][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right)
                return {row, mid};
            else if (mat[row][mid] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};