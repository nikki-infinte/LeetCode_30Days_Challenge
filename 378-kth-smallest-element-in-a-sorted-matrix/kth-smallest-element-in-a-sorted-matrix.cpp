class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

         int n = matrix.size();
        
        // Min-heap to store the {value, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> p;

        // Push the first column of each row into the min-heap
        for (int i = 0; i < n; i++) {
            p.push({matrix[i][0], {i, 0}});
        }
        int ans=0;
        while (k--) {
            auto element = p.top();
            p.pop();
            ans = element.first;
            int i = element.second.first;
            int j = element.second.second;

            // Push the next column element of the same row if exists
            if (j + 1 < n) {
                p.push({matrix[i][j + 1], {i, j + 1}});
            }
        }
        return ans;

    }
};