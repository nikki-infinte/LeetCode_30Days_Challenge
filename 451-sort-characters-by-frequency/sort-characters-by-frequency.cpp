class Solution {
public:
    string frequencySort(string s) {
        
        //approach 1:
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>umap;
        for(int i=0;i<s.size();i++)
        {
           umap[s[i]]++;
        }

        for(auto a:umap)
        {
            pq.push({a.second,a.first});
        }
        string ans="";
        while(!pq.empty())
        {
            int times=pq.top().first;
            int chara=pq.top().second;
            pq.pop();
            while(times--)
            {
                ans.push_back(chara);
            }
        }
        return ans;
    }
};