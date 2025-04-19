class Solution {
public:
    int thirdMax(vector<int>& nums) {
      sort(nums.begin(),nums.end());

      int n = nums.size();
      int first_l=nums[n-1];
      int second_l =0;

      if(n<3)return first_l;
      for(int i=n-1;i>=0;i--)
      {
        if(nums[i] !=first_l )
        {
            second_l = nums[i];
            break;
        }
      }


      for(int i=n-1;i>=0;i--)
      {
        if(nums[i] < second_l )
        {
            return nums[i];
        }
      }

      return first_l;
    }
};