class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        if(nums.size() < 2)return nums.size();
        int k =2,i = 2;
        while ( i < n )
        {
            if(nums[k-2] != nums[i])
            {
                nums[k] = nums[i];
                k++;
            }
            i++;
        }
        return k;

    }
};