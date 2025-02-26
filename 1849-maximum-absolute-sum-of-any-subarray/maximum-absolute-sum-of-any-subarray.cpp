class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        

   
        int maxsum =0;
        int sum =0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxsum = max(maxsum,sum);
            if(sum < 0)
            {
                sum =0;
            }
        }
       

       int minsum =0;
       int currsum =0;
       for(int i=0;i<nums.size();i++)
       {
        currsum = min(nums[i],currsum+nums[i]);
        minsum =min(minsum,currsum);
       
       }
       return max( abs(maxsum),abs(minsum));
    }
};