class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=0,curr=0;
        int maxone=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                maxone=max(maxone,prev+curr);
                prev=curr;
                curr=0;
            }else if(nums[i]==1){
                curr++;
            }
        }
         maxone=max(maxone,prev+curr);
        return (nums.size()==maxone)?maxone-1:maxone;
    }
};