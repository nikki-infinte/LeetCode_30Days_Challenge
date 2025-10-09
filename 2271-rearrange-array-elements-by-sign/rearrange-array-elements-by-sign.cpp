class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans;
        int pos = 0,neg = 0;
          while(pos < n && nums[pos] < 0 )pos++;
          while(neg < n && nums[neg] > 0)neg++;
        while( pos < n && neg < n) {
            ans.push_back(nums[pos]);
            ans.push_back(nums[neg]);
            pos++ ;
            neg ++ ;
          while(pos < n && nums[pos] < 0 )pos++;
          while(neg < n && nums[neg] > 0)neg++;

        }
        return ans;
    }
};