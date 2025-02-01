class Solution {
public:

    int atMost(vector<int>& nums, int goal)
    {
          int cnt=0;
        int i=0;
        int j=0;
        int n=nums.size();
        int sum=0;
        while ( j < n)
        {
            if( goal <0)return 0;
            sum+=nums[j];
            while( sum > goal && i<=j)
            {
                sum -=nums[i];
                i++;
            }
            cnt=cnt+(j-i+1);
            j++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        //     int cnt=0;
        // for(int i=0;i<nums.size() ;i++)
        // {   int sum=0;
        //     for(int  j=i;j<nums.size();j++)
        //     {
        //         sum+=nums[j];
        //         if(sum == goal )
        //         {
        //             cnt++;
        //         }else if(sum > goal ){
        //             continue;
        //         }
        //     }
        // }
        // return cnt;

        return atMost(nums , goal)-atMost(nums,goal-1);
      
    }
};