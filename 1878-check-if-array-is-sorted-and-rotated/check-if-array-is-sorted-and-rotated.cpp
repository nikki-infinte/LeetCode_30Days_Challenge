class Solution {
public:

    bool isSorted(vector<int>nums){
        int n = nums.size();
        int i=0;

        while( i+1 < n){
            if(nums[i] > nums[i+1])return false;
            i++;
        }
        return true;
    }
    void reverse(vector<int>&nums,int i,int j){
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }

    }
    vector<int>Rotate(int k,vector<int>nums){

        int n = nums.size();
        k%=n;
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
        reverse(nums,0,n-1);

        return nums;
    }
    bool check(vector<int>& nums) {
        
        if(isSorted(nums))return true;
        for(int i=1;i<nums.size();i++){
            vector<int>tmp = Rotate(i,nums);
            for(int i=0;i<tmp.size();i++){
                cout<<tmp[i]<<" ";
            }
            
            if(isSorted(tmp))return true;
        }
        return false;
        
    }
};