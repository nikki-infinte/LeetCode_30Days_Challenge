class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int pos = 0,neg = 0;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i] > 0)pos++;
            else if(nums[i] < 0)neg++;
        }
        return max(pos,neg);
    }
};