class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int cand = nums[0],count=1;
        int n = nums.size();
        for(int i=1;i<n ;i++){
            if(count == 0){
                cand = nums[i];
            }
            if(cand != nums[i]){
                count -- ;
            }else{
                count++;
            }
        }
        return cand;
    }
};