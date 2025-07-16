class Solution {
public:
    string reorganizeString(string s) {
         map<char, int> mp;
        int n = s.length();
        for (auto a : s) {
            mp[a]++;
            if (mp[a] > (n+1)/2)
                return "";
        }
       priority_queue<pair<int,char>> pq;
        for (auto a : mp) {
            pq.push({a.second, a.first});
        }
        string res = "";
        while (pq.size() >= 2) {
            auto [fre1, elem1] = pq.top();
            pq.pop();
            auto [fre2, elem2] = pq.top();
            pq.pop();

            res += elem1;
            fre1 -= 1;
            if (fre1 > 0) {
                pq.push({fre1, elem1});
            }

            res += elem2;
            fre2 -= 1;
            if (fre2 > 0) {
                pq.push({fre2, elem2});
            }
        }

        if (!pq.empty()) {
            auto [freq, ch] = pq.top();
            if (freq > 1) return "";
            res += ch;
        }

        return res;
    }
};