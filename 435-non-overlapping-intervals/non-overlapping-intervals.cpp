class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
       sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
});

        int count =0;
        int n = intervals.size();
    
        int end = intervals[0][1];
        for(int i=1;i< n ;i++)
        {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if(currStart < end)
            {
                count++;
               
            }else{
                end = currEnd;
            }
        }
        return count;
    }
};