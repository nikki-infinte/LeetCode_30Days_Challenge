class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     if (nums.empty()) return 0; // Handle edge case for empty array

    sort(nums.begin(), nums.end()); // Sort the array
    int count = 1; // Initialize count to 1 to count the first number
    int MaxCount = 1; // Initialize MaxCount to 1

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i-1]) {
            // If current number is the same as the previous one, skip it
            continue;
        } else if (nums[i] == nums[i-1] + 1) {
            // If current number is consecutive, increment count
            count++;
        } else {
            // If current number is not consecutive, update MaxCount and reset count
            MaxCount = max(MaxCount, count);
            count = 1; // Reset count for the new sequence
        }
    }

    MaxCount = max(MaxCount, count); // Final update for MaxCount

    return MaxCount;
    }
};