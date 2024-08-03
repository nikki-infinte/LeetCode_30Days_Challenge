class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int sum=0;
        int maxone=0;
        while(j<nums.size())
        {
           //sum
           sum+=nums[j];
           if( (j-i+1)-sum==k  || ((j-i+1)-sum <=k ))
           {
            maxone=max(maxone,(j-i+1));
          
           }
           if ((j - i + 1) - sum > k) {
            // Shrink the window from the left
            if (nums[i] == 1) {
                --sum;
            }
            ++i;
           }
           j++;
        }

        return maxone;
    }
};