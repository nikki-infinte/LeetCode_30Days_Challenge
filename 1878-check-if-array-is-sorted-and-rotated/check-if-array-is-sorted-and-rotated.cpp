class Solution {
public:
    bool check(vector<int>& nums) {
        
        int i=0,n = nums.size();
        while( i+1 < n){
            if(nums[i] <= nums[i+1])i++;
            else break;
        }
       
       int peak = i;

       for(int j=peak+1;j<n;j++){
        if(nums[j] > nums[0] || nums[j] > nums[peak])return false;
        if(j+1<n && nums[j] > nums[j+1])return false;
       }
       return true;
    }
};