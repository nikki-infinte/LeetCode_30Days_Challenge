class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Custom comparator: higher frequency comes first;
        // if frequency is the same, lexicographically smaller word comes first.
        auto cmp = [](pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        };

        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        unordered_map<string, int> umap;
        for (auto& word : words) {
            umap[word]++;
        }

        for (auto& entry : umap) {
            pq.push({entry.second, entry.first});
        }

        vector<string> ans;
        for (int i = 0; i < k && !pq.empty(); i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
