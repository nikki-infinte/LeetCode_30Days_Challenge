class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> tokens1, tokens2;
        string token;

        stringstream ss(version1);
        while(getline(ss, token, '.')) {
            tokens1.push_back(token);
        }

        stringstream ss2(version2);
        while(getline(ss2, token, '.')) {
            tokens2.push_back(token);
        }

        int n = max(tokens1.size(), tokens2.size());

        for(int i = 0; i < n; i++) {
            int a = i < tokens1.size() ? stoi(tokens1[i]) : 0;
            int b = i < tokens2.size() ? stoi(tokens2[i]) : 0;

            if(a < b) return -1;
            else if(a > b) return 1;
        }

        return 0;
    }
};
