class Solution {
public:
    vector<int> parent, rankA;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void union_f(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;

        if (rankA[px] > rankA[py]) {
            parent[py] = px;
        } else if (rankA[px] < rankA[py]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            rankA[py]++;
        }
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        rankA.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;

        typedef tuple<int, int, int> t; // cost, u, v
        priority_queue<t, vector<t>, greater<t>> pq;

        // Step 1: Build all edges with cost
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({cost, i, j});
            }
        }

        int totalCost = 0, count = 0;
        // Step 2: Kruskal's using priority queue
        while (!pq.empty() && count < n - 1) {
            auto [cost, u, v] = pq.top(); pq.pop();

            if (find(u) != find(v)) {
                union_f(u, v);
                totalCost += cost;
                count++;
            }
        }

        return totalCost;
    }
};
