class Solution {
public:
    struct cmp{
        bool operator()(pair<char,int> &p1, pair<char,int>&p2)
        {
            if(p1.first == p2.first)return p1.second < p2.second;
            return p1.first > p2.first;
        }
    
    };
    string clearStars(string s) {
        priority_queue< pair<char, int>, vector<pair<char, int>>, cmp > pq;
        int n = s.length();
        vector<bool> removed(n, false);

        for (int i = 0; i < n; i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else {
                // remove the smallest lexicographical character seen so far
                if (!pq.empty()) {
                    auto [ch, idx] = pq.top();
                    pq.pop();
                    removed[idx] = true;
                }
                removed[i] = true; // remove the '*' itself
            }
        }

        // Build the result string
        string result = "";
        for (int i = 0; i < n; i++) {
            if (!removed[i]) result += s[i];
        }

        return result;
    }
};
