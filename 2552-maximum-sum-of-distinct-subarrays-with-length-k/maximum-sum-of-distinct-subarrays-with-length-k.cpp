class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0;
        set<int>st;
        int i=0,j=0;
        long long maxsum=0;
        while(j<nums.size())
        {
            while(st.find(nums[j])!=st.end())
            {
               sum-=nums[i];
               st.erase(nums[i]);
               i++;
            }
             sum+=nums[j];
                st.insert(nums[j]);

            if(j-i+1 == k)
            {
                maxsum=max(maxsum,sum);
                //slide the window
                sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
           
            j++;
        }
        return maxsum;
    }
};