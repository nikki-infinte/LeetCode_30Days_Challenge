class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int sum=0;
        int len=INT_MAX;

        int total=accumulate(nums.begin(),nums.end(),0);
        if(target >total)return 0;

        while(j<n)
        {
            sum+=nums[j];
          
            while(sum>=target)
            {
                len=min((j-i+1),len);
                sum-=nums[i];
                i++;
            }

            j++;
        }
        return (len ==INT_MAX)?0:len;
    }
};