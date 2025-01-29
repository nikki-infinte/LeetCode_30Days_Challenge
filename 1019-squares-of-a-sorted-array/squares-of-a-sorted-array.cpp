class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        

        //using two pointer approach

        int left=0,right=nums.size()-1;
        vector<int>ans(right+1,0);
        int k=ans.size()-1;
     
        
        for(int k=ans.size()-1;k>=0;k--)
        {
            if(abs(nums[left]) > abs(nums[right]))
            {
                ans[k]=nums[left]*nums[left];
                left++;
            }else{
                ans[k]=nums[right]*nums[right];
                right--;
            }
        }
        return ans;


    }
};