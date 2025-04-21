class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1)return 1;

        int p_diff = nums[1]-nums[0];
        int counter = (p_diff != 0)?2:1;

        for(int i=2;i<nums.size();i++)
        {
            int curr_d = nums[i] - nums[i-1];

            if(curr_d > 0 && p_diff <=0 || ( curr_d < 0 && p_diff >=0)){
                counter++;
                p_diff = curr_d;
            }
        }
        return counter;
    }
};