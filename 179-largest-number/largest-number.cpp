class Solution {
public:
    // Custom comparator to decide order based on concatenated result
    static bool compare(int a, int b) {
        std::string strA = std::to_string(a);
        std::string strB = std::to_string(b);
        return (strA + strB) > (strB + strA);
    }
    
    std::string largestNumber(std::vector<int>& nums) {
        // Sort nums based on the custom comparator
        std::sort(nums.begin(), nums.end(), compare);

        // Handle edge case where the highest number is 0
        if (nums[0] == 0) {
            return "0";
        }

        // Concatenate the numbers to form the largest number
        std::string ans;
        for (int num : nums) {
            ans += std::to_string(num);
        }

        return ans;
    }
};