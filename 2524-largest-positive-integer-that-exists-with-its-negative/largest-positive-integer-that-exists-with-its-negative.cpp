class Solution {
public:
    int findMaxK(vector<int>& nums) {

        unordered_set<int>num_set(nums.begin(),nums.end());
        int max_k = -1;
        for(auto n:nums)
        {
            if(num_set.count(-n))
            {
                max_k = max(max_k, abs(n));
            }
        }

         return max_k;
    }
};