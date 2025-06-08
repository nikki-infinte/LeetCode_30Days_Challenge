class Solution {
public:

    bool allOne(vector<int>nums,int k,int n)
    {
        int count =0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i] == -1){
                nums[i] = 1;
                nums[i+1]*=-1;
                count++;
            }

        }
        return count<=k && nums[n-1]==1;
    }

    bool allzero(vector<int> nums, int k, int n) {
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == 1) {
                nums[i] = -1;
                nums[i + 1] *= -1;
                count++;
            }
        }
        return count <= k && nums[n - 1] == -1;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        int n=nums.size();
        if(allOne(nums,k,n))return true;

        return allzero(nums,k,n);
    }
};