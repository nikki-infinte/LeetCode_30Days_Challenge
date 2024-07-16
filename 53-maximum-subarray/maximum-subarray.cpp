class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        for(auto n:nums)
        {
            sum +=n;
            maxi=max(sum,maxi);
            if(sum < 0)
            {
                sum=0;
            }
        }
        return maxi;
    }
};