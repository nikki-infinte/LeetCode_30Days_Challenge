class Solution {
public:
    int searchInsert(vector<int>& nums, int x) {
        int low = 0;
        int high = nums.size();
        int ans =high;
        high--;
        while(low <=high){
            int mid = (low+high)/2;

            if(nums[mid]>=x){
                ans = mid;
                high=mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};