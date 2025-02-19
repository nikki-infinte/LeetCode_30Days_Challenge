class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int low=0;
        int high=nums.size()-1;
        int ans=nums[0];
        while(low<=high)
        {
            int mid=low + (high-low)/2;
            if(nums[mid] >= nums[0]){
                //leftly sorted array
                low=mid+1;
            }else
            {
                //rightly sorted array
                ans=nums[mid];
                high=mid-1;
            }
        }
        return ans;
        
    }
};