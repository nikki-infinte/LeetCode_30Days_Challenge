class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;

        for(int i=0;i<nums.size();i++){

           string num = to_string(nums[i]);
            for(auto &a:num){
                ans.push_back(a-'0');
            }
        
        }
        return ans;
    }
};