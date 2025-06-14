class Solution {
public:
    int minMaxDifference(int num) {
        // <element , index>
        unordered_map<int, vector<int>> umap;
        int i = 0;
        string n = to_string(num);
        for (auto a : n) {
            umap[a - '0'].push_back(i);
            i++;
        }

        int minElem = INT_MAX, maxElem = INT_MIN;

        // MIN: Replace occurrences of each digit with '0' and compute min
        for (auto a : umap) {
            int elem = a.first;
            string new_num = "";
            string org = to_string(num);
            for (int i = 0; i < org.size(); i++) {
                if (org[i] - '0' == elem) {
                    new_num += '0';
                } else {
                    new_num += org[i];
                }
            }
            minElem = min(minElem, stoi(new_num));
        }

        // MAX: Replace occurrences of each digit with '9' and compute max
        for (auto a : umap) {
            int elem = a.first;
            string new_num = "";
            string org = to_string(num);
            for (int i = 0; i < org.size(); i++) {
                if (org[i] - '0' == elem) {
                    new_num += '9';
                } else {
                    new_num += org[i];
                }
            }
            maxElem = max(maxElem, stoi(new_num));  // Fixed this line
        }

        return maxElem - minElem;
    }
};
