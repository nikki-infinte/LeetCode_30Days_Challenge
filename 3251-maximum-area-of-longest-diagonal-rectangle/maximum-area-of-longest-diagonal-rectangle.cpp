class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ansArea = 0;
        double maxDiagonal = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int len = dimensions[i][0];
            int wid = dimensions[i][1];
            double diagonal = sqrt(len * len + wid * wid);
            int area = len * wid;

            if (diagonal > maxDiagonal) {
                maxDiagonal = diagonal;
                ansArea = area;
            } else if (diagonal == maxDiagonal) {
                ansArea = max(ansArea, area);
            }
        }
        return ansArea;
    }
};
