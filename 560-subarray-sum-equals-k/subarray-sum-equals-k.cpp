class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int n = nums.size();
        if(n == 1 && nums[0] == k)return 1;


        int sum =0,cnt =0;
        for(int i=0;i<n;i++){
            sum += nums[i];

            if(mp.find(sum-k)!=mp.end()){
                cnt+=mp[sum-k];
            }
            mp[sum]++;
        }
      //  if(sum == k)cnt++;
        return cnt;
    }
};