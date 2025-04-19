class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Sort intervals based on the starting point
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        int arrow =1;
        int start = points[0][0];
        int end = points[0][1];
        int n = points.size();

        for(int i=1;i<n;i++){

            int curStart = points[i][0];
            int currEnd = points[i][1];

            if(curStart <= end)
            {
                start = max(curStart,start);
                end = min(end,currEnd);

            }else{
                start = curStart;
                end=currEnd;
                arrow++;
            }
        }
        return arrow;
    }
};