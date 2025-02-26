class Solution {
public:

    int minSum(vector<int>&vec)
    {
        int sum=0;
        int n=vec.size();
        int mnsum = INT_MAX;

        for(int i=0;i<n;i++)
        {
            sum=min(vec[i],sum+vec[i]);
            mnsum = min(mnsum,sum);

        }
        return mnsum;
    }

    int maxSum(vector<int>&vec)
    {
         int sum=0;
        int n=vec.size();
        int mnsum = INT_MIN;

        for(int i=0;i<n;i++)
        {
            sum=max(vec[i],sum+vec[i]);
            mnsum = max(mnsum,sum);

        }
        return mnsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int total_sum=accumulate(nums.begin(),nums.end(),0);

        int mnSum =minSum(nums);
        int mxSum =maxSum(nums);

        int circular =total_sum -mnSum;

        if(mxSum > 0)return max(mxSum,circular);
        return mxSum;
    }
};