class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n<=4)
        return 0;
        int start = 0, end = nums[n-1]-nums[0];
        int ans = end;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(check(nums, mid, n)){
                ans = mid;
                end = mid -1;
            } else {
                start = mid+1;
            }
        }
        return ans;
    }

    //sliding window of size n-3
    bool check(vector<int> &nums, int limit, int n) {
        if(nums[n-4]-nums[0]<=limit)
        return true;
        if(nums[n-3]-nums[1]<=limit)
        return true;
        if(nums[n-2]-nums[2]<=limit)
        return true;
        if(nums[n-1]-nums[3]<=limit)
        return true;
        return false;
    }
};