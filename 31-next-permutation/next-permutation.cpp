class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        

        //determine LDE 
        int n = nums.size();
        int i = n-2;
        while( i>=0 && nums[i] >= nums[i+1])
        {
            i--;
        }

        if( i >=0)
        {
            //find the smallest elemnt from larger than nums[i]
            int j = n-1;
            while(nums[j] <=nums[i])
            {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());


    }
};