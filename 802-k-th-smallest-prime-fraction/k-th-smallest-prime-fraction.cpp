class Solution {
public:
    typedef pair<float, pair<int, int>> P;

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<P, vector<P>, greater<P>> min_heap;

        // Push initial fractions arr[0]/arr[i] for i = 1 to n-1
        for (int i = 1; i < n; i++) {
            float frac = float(arr[0]) / arr[i];
            min_heap.push({frac, {0, i}});
        }

        P top_pair;
        while (k-- > 0) {
            top_pair = min_heap.top();
            min_heap.pop();

            int i = top_pair.second.first;
            int j = top_pair.second.second;

            // Try moving to the next numerator
            if (i + 1 < j) {
                float new_frac = float(arr[i + 1]) / arr[j];
                min_heap.push({new_frac, {i + 1, j}});
            }
        }

        // Get final answer
        int i = top_pair.second.first;
        int j = top_pair.second.second;
        return {arr[i], arr[j]};
    }
};
