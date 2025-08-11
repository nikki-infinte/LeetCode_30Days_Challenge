class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> power;

        for (int i = 0; i < 31; i++) {
            if ((n >> i) & 1) {
                power.push_back(1 << i);
            }
        }

        vector<int> ans;
        for (auto& q : queries) {
            long long prod = 1;
            for (int k = q[0]; k <= q[1]; k++) {
                prod = (prod * power[k]) % MOD;
            }
            ans.push_back((int)prod);
        }
        return ans;
    }
};
