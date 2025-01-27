class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int zero= accumulate(nums.begin(),nums.end(),0);
        if(k==0 && zero==0)
        {
            return 0;
        }
        // //two pointer apprach
        // int n=nums.size();
        // int power = k;
        // int i=0;int j=0;
        // int maxlen=0;

        // int sum=0;
        // while(j<n)
        // {
        //     if(nums[j]==0 && power > 0)
        //     {
        //         power--;
        //     }
        //     sum+=nums[j];

        //     if(power==0)
        //     {
        //          maxlen=max(maxlen,j-i+1);
        //         while( power < k && i < j)
        //         {
        //             if(nums[i]==0){
        //                 power++;
        //             }
        //             sum=sum-nums[i];
        //             i++;
        //         }
                 
        //     }
          
        //     j++;

        // }
        // return maxlen;

        int zerocnt=0;
        int i=0,j=0;
        int maxlen=INT_MIN;
        int n=nums.size();

        while( j < n )
        {
            if(nums[j] == 0)
            {
                zerocnt++;
            }

            if(zerocnt <= k)
            {
                maxlen=max(maxlen , j-i+1);
            }else{
                while(zerocnt > k && i<j)
                {
                    if(nums[i]==0)
                    {
                        zerocnt--;
                        
                    }
                    i++;
                }
            }
            j++;
        }
        return maxlen;
    }
};