class Solution {
public:

    void merged(vector<int>&nums,int low , int high ,int mid){

        vector<int>temp;
        int left = low , right = mid+1;

         while (left <= mid && right <= high) {
        if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
        else temp.push_back(nums[right++]);
    }

    while (left <= mid) temp.push_back(nums[left++]);
    while (right <= high) temp.push_back(nums[right++]);

    for (int i = low; i <= high; ++i) {
        nums[i] = temp[i - low];
    }


    }
    void merge(vector<int>&nums,int low,int high){

        if(low >= high)return ;
        int mid = (low + high)/2;
        merge(nums,low,mid);
        merge(nums,mid+1,high);

        merged(nums,low,high,mid);
      
    }
    vector<int> sortArray(vector<int>& nums) {
        merge(nums,0,nums.size()-1);
        return nums;
    }
};