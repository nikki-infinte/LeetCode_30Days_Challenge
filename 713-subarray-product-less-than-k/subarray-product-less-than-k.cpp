class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0;
          if (k <= 1) return 0; 
        int n = nums.size();
        int p =1,count=0;
        while( j < n)
        {
            p*=nums[j];
            while( p >= k)
            {
                p/=nums[i];
                i++;
            }

            
                count+=(j-i+1);
            
            j++;
        }
        return count;
    }
};