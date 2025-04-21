class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>umap;

        for(int i=0;i<nums.size();i++)
        {
            umap[nums[i]]++;
        }

        for(auto a:umap)
        {
            pq.push({a.second,a.first});
        }

        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};