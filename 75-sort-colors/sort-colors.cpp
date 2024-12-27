class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch National Flag
        int high=nums.size()-1;
        int low=0;
        int mid=0;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            {
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
                
            }

        }

    }
};