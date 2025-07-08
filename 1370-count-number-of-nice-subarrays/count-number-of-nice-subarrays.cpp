class Solution {
public:


    int atmost(vector<int>&nums,int k){
        int n =nums.size();
        int i=0,j=0;
        int res =0  ;
        while(j<n){
            if(nums[j]%2 != 0)k--;
            while(i<=j && k < 0){
                if(nums[i]%2 !=0)k++;
                i++;
               
            }
            res += j-i+1;

            j++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       // if( k == 1)return atmost(nums,k);
       return atmost(nums,k)-atmost(nums,k-1);
    }
};