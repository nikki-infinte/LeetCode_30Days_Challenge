class Solution {
public:
    int maximumGap(vector<int>& nums) {
        //brute force
        sort(nums.begin(),nums.end());

        int maxdiff = 0;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            maxdiff = max(maxdiff , abs(nums[i] - nums[i+1]) );
        }
        return maxdiff;
    }
};