class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums.begin() , nums.end(),target)-nums.begin();
        int second = upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        if (first == nums.size() || nums[first] != target) {
        return {-1, -1};
    }
 
        
        return {first,second};
    }
};