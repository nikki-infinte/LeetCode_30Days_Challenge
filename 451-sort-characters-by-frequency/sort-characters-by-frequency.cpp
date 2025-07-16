class Solution {
public:
    string frequencySort(string s) {
      
        unordered_map<char,int> mp;

        for(auto a : s)
            mp[a]++;
        priority_queue<pair<int,char>>pq;
        for(auto m:mp){
            pq.push({m.second,m.first});
        }
        string ans="";
        while(!pq.empty()){
            auto [q,char1]=pq.top();
            pq.pop();

            while(q--){
                ans+=char1;
            }
        }
        return ans;
     
    }
};