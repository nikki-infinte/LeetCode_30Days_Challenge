class Solution {
public:
    string frequencySort(string s) {
        
        //map
        unordered_map<char,int> mp;
        for(auto c: s)
        {
            mp[c]++;
        }
       priority_queue<pair<int, char>> maxheap;
      for (const auto& entry : mp) {
         maxheap.push({entry.second, entry.first});
        }

        string res;
        while(!maxheap.empty())
        {
            auto top = maxheap.top();
            maxheap.pop();
            res += string(top.first, top.second); 
        }
        return res;
    }
};