class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int,int> mp;
        for(auto a:nums)
        {
            for(int i=0;i<a.size();i++)
            {
                mp[a[i]]++;
            }
        }
      vector<int> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            // Check if the value (second) is equal to the number of vectors
            if (it->second == nums.size()) {
                ans.push_back(it->first);
            }
        }

        return ans;
    }

};