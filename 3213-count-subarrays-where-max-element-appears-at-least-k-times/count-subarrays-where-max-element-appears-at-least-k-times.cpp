class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;

        int i=0,j=0;
        int n = nums.size();

        int maxelem = *max_element(nums.begin(),nums.end());
        int maxCount =0;
        while( j < n )
        {
            if(nums[j] == maxelem){
                maxCount++;
            }

            while(maxCount >= k)
            {
                res += n-j;
                if(nums[i] == maxelem)maxCount--;
                i++;
            }
            j++;
        }

        return res;

    }
};