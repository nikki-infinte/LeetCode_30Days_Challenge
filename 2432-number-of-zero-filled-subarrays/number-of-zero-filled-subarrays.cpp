class Solution {
public:
    int countSubarray(vector<int>&nums,int len){

       int zCount = 0;
       int i=0,j=0;
       int n = nums.size();
       int ans =0;
       while(  j < n){
            if(nums[j] == 0)zCount++;

            if( j-i+1 > len){
                if(nums[i] == 0)zCount--;
                i++;
            }
            if(j-i+1 == len && zCount == len){
                ans++;
            }
            j++;
       }
       return ans;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum =0 , streak =0;
        int n =nums.size();
        // for(int i=1;i<n;i++){

        //     sum += countSubarray( nums , i);
        // }
        // return sum;


        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                streak++;
                sum += streak;
            }else{
                streak=0;
            }
        }
        return sum;
    }
};