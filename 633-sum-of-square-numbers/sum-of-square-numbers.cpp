class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c == 1 || c == 0) return true;  // Base cases
        
        long long low = 0;  // Use long long to avoid overflow
        long long high = static_cast<long long>(sqrt(c));  // Highest possible value for a square

        while (low <= high) {
            long long sum = (low * low) + (high * high);  // Calculate the sum of squares
            if (sum == c) {
                return true;  // Found a pair
            } else if (sum > c) {
                high--;  // Decrease the larger number
            } else {
                low++;  // Increase the smaller number
            }
        }
        return false;  // No valid pair found
    }
};
