class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    int n = prices.size();
    // find out next greatest element 

        stack<int>st;
        vector<int>ans(n,0);
        int j = n-1;
        while(j >=0)
        {
            while(!st.empty() && st.top() <= prices[j])
            {
                st.pop();
            }
            if(st.empty())
            {
                ans[j] = prices[j];
                st.push(prices[j]);
            }
            else{
                ans[j] = st.top();
            }
            j--;
        }

        int maxProfit = INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxProfit = max(maxProfit, ans[i] - prices[i]);
        }
        return maxProfit;
    }
};