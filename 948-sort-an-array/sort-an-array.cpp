class Solution {
public:
    void merge(vector<int>& nums,int low,int high,int mid)
    {
        int left = low;
        int right = mid + 1;
        vector<int> newarr(high - low + 1);
        int i = 0;
        
        while(left <= mid && right <= high) {
            if(nums[left] <= nums[right]) {
                newarr[i++] = nums[left++];
            } else {
                newarr[i++] = nums[right++];
            }
        }
        while(left <= mid) {
            newarr[i++] = nums[left++];
        }
        while(right <= high) {
            newarr[i++] = nums[right++];
        }
        for(int i = 0; i < newarr.size(); i++) {
            nums[low + i] = newarr[i];
        }
    }
    void mergeSort(vector<int>&nums,int low,int high)
    { 
         if(low <high) {
          
        
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, high, mid);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};