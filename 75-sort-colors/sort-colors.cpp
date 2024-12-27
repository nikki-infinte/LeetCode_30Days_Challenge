class Solution {
public:
    void sortColors(vector<int>& nums) {
       int ones=0;
       int twos=0;
       int zeros=0;

       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]==1)ones++;
        if(nums[i]==2)twos++;
        if(nums[i]==0)zeros++;
       }
       for(int i=0;i<zeros;i++)
       {
        nums[i]=0;
       }
       for(int i=zeros;i<zeros+ones;i++)
       {
        
        nums[i]=1;
       }
       for(int i=zeros+ones;i<zeros+ones+twos;i++)
       {
        nums[i]=2;
       }
    }
};