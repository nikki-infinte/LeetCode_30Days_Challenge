class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
       /* previous submisson 
        int n=nums.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++)
        {
            temp[(i+k)%n]=nums[i];
        }
        nums=temp;
        */
/*
        better approach:
        int n=nums.size();
        while(k!=0)
        {

            int temp=nums[n-1];
            for(int i=0;i<n;i++)
            {
                nums[i+1]=nums[i];
            }
        }
        */
        //reversal approach
         k = k % nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);


    }
    void reverse(vector<int>& nums,int s,int e)
    {
        while(s<=e)
        {
            int tmp=nums[s];
            nums[s]=nums[e];
            nums[e]=tmp;
            s++;
            e--;

        }
    }
};