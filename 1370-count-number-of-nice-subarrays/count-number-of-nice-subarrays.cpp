class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int i=0,j=0;
        int n = nums.size();

        int cnt =0;
        int temp=0;

        int ans=0;
        while( j < n )
        {
            if(nums[j] % 2){
                cnt++;
                temp = 0;
            }

            while(  cnt  == k)
            {
                if(nums[i]%2)cnt--;
                temp++;
                i++;
            }

            
                ans+=temp;
            
            j++;
        }
        return ans;
    }
};