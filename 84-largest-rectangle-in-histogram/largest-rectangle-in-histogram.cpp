class Solution {
public:
  vector<int> nextsmallest(vector<int>& heights, int n) {
    stack<int> s;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--) {
        int curr = heights[i];
        while (!s.empty() && heights[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = (s.empty() ? -1 : s.top());
        s.push(i); // Push the index
    }
    return ans;
}

vector<int> prevsmallest(vector<int>& heights, int n) {
    stack<int> s;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int curr = heights[i];
        while (!s.empty() && heights[s.top()] >= curr) {
            s.pop();
        }
        ans[i] = (s.empty() ? -1 : s.top());
        s.push(i); // Push the index
    }
    return ans;
}

    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        vector<int>next(n);
        next=nextsmallest(heights,n);

        vector<int>prev(n);
        prev=prevsmallest(heights,n);

        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            if(next[i]==-1)
            {
                next[i]=n;
            }
            int b=next[i]-prev[i]-1;

            area=max(area,l*b);
        }
        return area;
    }
};