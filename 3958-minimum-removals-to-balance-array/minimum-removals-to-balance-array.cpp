class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
         int maxlen = 0;
       for(int i=0,j=0;j<n;j++){
        while(nums[j] > (long long)nums[i]*k){
            i++;
        }
        maxlen = max(maxlen,j-i+1);
       }
       return n - maxlen;
    }
};