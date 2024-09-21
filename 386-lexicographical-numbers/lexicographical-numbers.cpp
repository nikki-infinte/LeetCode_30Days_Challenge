class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>st;
        for(int i=1;i<=n;i++)
        {
            st.push_back(to_string(i));
        }
        sort(st.begin(),st.end());
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=stoi(st[i]);
        }

        return ans;
    }
};