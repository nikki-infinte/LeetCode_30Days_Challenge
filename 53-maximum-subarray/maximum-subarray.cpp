class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];  // Initialize maxSum with the first element
        
        int currentSum = nums[0];  // Keep track of the sum of the current subarray
        for (int i = 1; i < n; i++) {
            currentSum = max(nums[i], currentSum + nums[i]);  // Either start new subarray or extend the existing one
            maxSum = max(maxSum, currentSum);  // Update maxSum
        }
        
        return maxSum;
    }
};