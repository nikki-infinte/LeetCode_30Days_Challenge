class Solution {
public:
    bool validMountainArray(vector<int>& nums) {
        int n = nums.size();

        if( n < 3)return false;
        

        int i=0;
        while( i < n-1 && nums[i] < nums[i+1])i++;
        if( i== 0 || i == n-1)return false;

        while( i < n-1 && nums[i] > nums[i+1])i++;
       
        return i == n - 1;
    }
};