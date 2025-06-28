class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>>p;
        int i=0;
        for(auto a:nums)
        {
            p.push({a,i});
            i++;
        }

        vector<int>visit(nums.size(),0);

        while(!p.empty() && k>0)
        {
            auto a = p.top();
            p.pop();
            visit[a.second]=1;
            k--;
        }

        vector<int>ans;
        for(int i=0;i<visit.size();i++)
        {
            if(visit[i] == 1)
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};