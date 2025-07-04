class Solution {
public:

    bool split(vector<int>nums,int k,int mid){
        int sum = 0;
        int count =1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+sum <= mid){
                sum+=nums[i];
            }else{
                sum = nums[i];
                count++;
            }
        }
        return count <= k;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans =low;
        while(low<=high){
            int mid =( low + high)/2;

            if(split(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};