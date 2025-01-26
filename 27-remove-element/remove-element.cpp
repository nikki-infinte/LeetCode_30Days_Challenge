class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx=0;
        for(int j=0;j<nums.size();j++)
        {
            if(idx<nums.size() && nums[j] != val)
            {
               
                nums[idx]=nums[j];
                 idx++;
            }
        }
        return idx;
    }
};