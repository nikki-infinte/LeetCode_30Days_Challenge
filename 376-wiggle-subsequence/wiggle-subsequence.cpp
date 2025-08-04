class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;

        int preD = nums[1] - nums[0];
        int len = (preD != 0) ? 2 : 1;
        for (int i = 2; i < nums.size(); i++) {
            int curr = nums[i]-nums[i-1];
            if ((preD <= 0 && curr > 0) || (preD >= 0 && curr < 0)) {
                len++;
                preD = curr;
            }
        }
        return len;
    }
};