class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElem = *max_element(nums.begin(),nums.end());

        int maxStreak=0,streak=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == maxElem)streak++;
            else {
                maxStreak = max(maxStreak,streak);
                streak =0;
                
            }
        }
         maxStreak = max(maxStreak,streak);
        return maxStreak;
    }
};