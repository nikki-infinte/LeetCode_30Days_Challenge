class Solution {
public:
    int minOperations(vector<int>& nums) {
       stack<int>st;
       int ans=0;

       for(int n:nums)
       {
        while(!st.empty() && n < st.top())
        {
            st.pop();
        }
        if( st.empty() || n > st.top() )
        {
            if(n > 0)ans++;
            st.push(n);
        }

       }
       return ans;
    }
};