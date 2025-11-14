class Solution {
public:

    int minSumSubarray(vector<int>&nums){
        int n = nums.size();

        int sum = nums[0];
        int minSum = nums[0];
        for(int i=1;i<n;i++){
            
            sum = min(nums[i],sum+nums[i]);
            minSum = min(minSum,sum);
        }
        return minSum;
    }
    int maxSumSubarray(vector<int>&nums){
        int n = nums.size();

        int sum = nums[0];
        int minSum = nums[0];
        for(int i=1;i<n;i++){
            
            sum = max(nums[i],sum+nums[i]);
            minSum = max(minSum,sum);
        }
        return minSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int total = accumulate(nums.begin(),nums.end(),0);
        int maxsum = maxSumSubarray(nums);
        int minsum = minSumSubarray(nums);

        if(maxsum > 0){
            return max(maxsum, total - minsum);
        }
        return maxsum;
    }
};