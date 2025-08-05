class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[0] == b[0])return a[1] > b[1];
            return a[0] < b[0]; 
        });

        int s = intervals[0][0];
        int e = intervals[0][1];
        int count =1;
        for(int i=1;i<n;i++){
            if(e >= intervals[i][1]){
                continue;
               // e  = max(intervals[i][1],e);
            }else{
                count++;
                s =intervals[i][0];
                e =intervals[i][1];
            }
        }
        return count;
    }
};