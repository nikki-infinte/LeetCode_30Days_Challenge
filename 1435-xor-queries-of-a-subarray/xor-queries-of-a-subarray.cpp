class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;

        for(auto a:queries)
        {
            int start=a[0];
            int goal=a[1];
            int xora=0;
            for(int i=start;i<=goal;i++)
            {
                xora^=arr[i];
            }
            ans.push_back(xora);
        }
        return ans;
    }
};