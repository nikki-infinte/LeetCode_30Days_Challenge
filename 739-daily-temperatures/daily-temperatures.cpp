class Solution {
public:

    vector<int> dailyTemperatures(vector<int>& temperatures)
     {
        
        int n = temperatures.size();
        stack<int>st;
        vector<int>nge(n,-1);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                nge[i] = st.top();
            }
            st.push(i);
        }

        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            if(nge[i] != -1)
            {
                ans[i] = abs(nge[i] - i);
            }else{
                ans[i] = 0;
            }
        }
        return ans;
    }
};