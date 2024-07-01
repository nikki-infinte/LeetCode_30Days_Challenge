class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,maxcount=0;
    int i=0;
    while(i<nums.size())
    {
        if(nums[i]==1)
        {
            count+=1;
        }
        if(nums[i]==0)
        {
            maxcount=max(maxcount,count);
            count=0;
        }
        i++;
    }
     maxcount=max(maxcount,count);
    return maxcount;
    }
};