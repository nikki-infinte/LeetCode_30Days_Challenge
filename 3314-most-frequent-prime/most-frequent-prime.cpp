class Solution {
public:
    int n, m;
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    unordered_map<int, int> mp;
    bool isPrime(int num) {
        if (num <= 10)
            return false;
        for (int i = 2; i * i <= num; ++i)
            if (num % i == 0)
                return false;
        return true;
    }

    void DFS(int i, int j, vector<vector<int>>& mat, int num,
             vector<vector<int>>& visit, int dir) {

        if (isPrime(num)) {
            mp[num]++;
        }

        int newi = i + dx[dir];
        int newj = j + dy[dir];

        if (newi >= 0 && newj >= 0 && newi < n && newj < m &&
            visit[newi][newj] == 0) {

            visit[newi][newj] = 1;
            DFS(newi, newj, mat, num * 10 + mat[newi][newj], visit, dir);
            visit[newi][newj] = 0; // backtrack for other paths
        }
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int dir = 0; dir < 8; ++dir) {
                    vector<vector<int>> visit(n, vector<int>(m, 0));
                    visit[i][j] = 1;
                    DFS(i, j, mat, mat[i][j], visit, dir);
                }
            }
        }

        int maxcnt = 0;
        int maxElem = -1;
        for (auto e : mp) {
            if (e.second > maxcnt ||
                (e.second == maxcnt && e.first > maxElem)) {
                maxElem = e.first;
                maxcnt = e.second;
            }
        }

        return maxElem;
    }
};