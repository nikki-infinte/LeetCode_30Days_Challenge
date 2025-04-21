class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>> > min_heap;

        for(int i=0;i<n;i++)
        {
            min_heap.push({abs(arr[i] - x),i});
        }

        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            int c = min_heap.top().second;
            min_heap.pop();
            ans.push_back(arr[c]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};