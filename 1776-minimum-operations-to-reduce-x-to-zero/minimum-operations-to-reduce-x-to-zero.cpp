class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        

          int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if (target < 0) return -1;  // If the sum of nums is less than x, return -1
        
        int left = 0, current_sum = 0, max_len = -1;
        
        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];
            
            // Shrink the window from the left if current_sum exceeds the target
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }
            
            // If we found a valid subarray with sum equal to target
            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        return (max_len == -1) ? -1 : (n - max_len); 
    }
};