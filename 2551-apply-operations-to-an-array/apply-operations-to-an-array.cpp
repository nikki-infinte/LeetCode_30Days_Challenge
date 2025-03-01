class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int  n =nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] == nums[i+1])
            {
                nums[i]= 2*nums[i];
                nums[i+1] = 0;
            }
        }

        // Move Zero to end

        int j = -1;
        for(int i=0;i < n;i++)
        {
            if(nums[i]  == 0)
            {
                j=i;
                break;
            }
        }

        if( j == -1)return nums;

        for(int i= j+1 ;i<n;i++)
        {
            if( nums[i] != 0 )
            {
                swap(nums[i] ,nums[j]);
                j++;
            }
        }
        return nums;
        
    }
};