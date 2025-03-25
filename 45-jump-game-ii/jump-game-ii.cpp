class Solution {
public:

    //using recursion

     int jumpOp(vector<int>& nums, int indx, vector<int>& memo) {
        // Base case: reached end
        if (indx >= nums.size() - 1) return 0;
        
        // Check memoization
        if (memo[indx] != -1) return memo[indx];
        
        // Handle zero jump case
        if (nums[indx] == 0) return INT_MAX;
        
        int minJump = INT_MAX;
        
        // Try all possible jumps
        for (int i = 1; i <= nums[indx]; i++) {
            int nextJump = jumpOp(nums, indx + i, memo);
            
            // Only update if next position can reach the end
            if (nextJump != INT_MAX) {
                minJump = min(minJump, 1 + nextJump);
            }
        }
        
        // Store result in memo table
        return memo[indx] = minJump;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>memo(n,-1);
        return jumpOp(nums,0,memo);
    }
};