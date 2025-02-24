class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {


        int n = nums.size();
        vector<int>ans(n,0);


        int low=0;
        int right =n-1;
        for(int k = n-1;k>=0;k--)
        {
            if(abs( nums[low]) > abs(nums[right]))
            {
                ans[k] = nums[low]*nums[low];
                low++;
            }else{
                ans[k] = nums[right] * nums[right];
                right--;
            }
        }
        return ans;
    }
};