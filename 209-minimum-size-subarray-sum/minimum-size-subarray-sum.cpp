class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int total =accumulate(nums.begin(),nums.end(),0);
        if(total < target)
        {
            return 0;
        }

        int i=0;
        int j=0;
        int n = nums.size();
        int sum=0;
        int maxlen=INT_MAX;
        while(j < n)
        {
            sum+=nums[j];
            while((i <= j) && (sum >= target))
            {
                maxlen=min(maxlen , j-i+1);
                sum=sum-nums[i];
                i++;
            }
            j++;
            
        }
        return maxlen;
    }
};