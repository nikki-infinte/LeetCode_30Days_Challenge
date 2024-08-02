class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
      

        // number of ones will be
        int count=0;
        for(int i=0;i<n;i++)
        {
            count+=nums[i];
        }
         if (count == 0 || count == n) {
            return 0;
        }
        //number of ones==count winfow is size of no of onces

        int i=0;
        int j=0;
        int currone=0;
        int maxcount=0;
        while(j<2*n)
        {
            if(nums[j%n]==1)
            {
                currone++;
            }
            if(j-i+1 > count)
            {
                currone -=nums[i%n];
                i++;
            }
            maxcount=max(maxcount,currone);
            j++;
        }
        return count-maxcount;
    }
};