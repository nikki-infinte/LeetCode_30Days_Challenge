class Solution {
public:

    void reverse(vector<int>&nums,int i,int j){
        while(i < j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }

    }
    void rotate(vector<int>& nums, int k) {
        
        //reversal algorithm 
        int n = nums.size();
        
        k%=n;

        // reverse(nums,n-k,n-1);
        // reverse(nums,0,n-k-1);
        // reverse(nums,0,n-1);
        
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};