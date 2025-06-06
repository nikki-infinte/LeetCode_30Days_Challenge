class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        int i=0;
        int j=0;
        long long res =0;
        unordered_map<int,int>mp;
        long long pairs =0;
        int n = nums.size();

        while( j < n)
        {
            pairs+=mp[nums[j]];
            mp[nums[j]]++;


            while( pairs >=k)
            {
                res += (n-j);
                mp[nums[i]]--;
                pairs -=mp[nums[i]];
                i++;
            }
            j++;
        }
        return res;
    }
};