class Solution {
public:
    bool canJump(vector<int>& nums) {
       
        if( nums.size() == 1 )
        {
            return true;
        }
       int farthest = 0,last_indx =nums.size();

       for(int i=0;i<=farthest &&  farthest<last_indx ; i++ )
       {
        farthest = max(farthest,nums[i]+i);
       }

       return farthest >= nums.size()-1 ;
    }
};