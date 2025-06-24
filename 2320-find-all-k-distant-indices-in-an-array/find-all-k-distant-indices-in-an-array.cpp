class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        
        vector<int>keyPresent;
        int n = nums.size();

       for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                keyPresent.push_back(i);
            }
        }

        vector<int>ans;
         for (int i = 0; i < n; ++i) {
            for (int idx : keyPresent) {
                if (abs(i - idx) <= k) {
                    ans.push_back(i);
                    break; 
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};