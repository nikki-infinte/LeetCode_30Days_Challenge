class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size()-2;i++)
        {
            float sum=float(nums[i] )+float(nums[i+2]);
            
            float value=float(nums[i+1])/2;
            
            if(sum==value)
            {
                count++;
            }
            
        }
        return count;
    }
};