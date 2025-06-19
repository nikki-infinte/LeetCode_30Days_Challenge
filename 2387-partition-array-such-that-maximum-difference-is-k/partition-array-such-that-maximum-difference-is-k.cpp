class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int minVal=nums[0];
        int count =0;
        for(int i=1;i<nums.size();i++)
        {

            if( nums[i] - minVal > k){
                count++;
                minVal = nums[i];
            }
        }
        return count+1;
    }
};