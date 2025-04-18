class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size()-1;
        int sum=0;
        for(int i=n-1;i>=0;i-=2)
        {
            sum += nums[i];
        }
        return sum;
    }
};