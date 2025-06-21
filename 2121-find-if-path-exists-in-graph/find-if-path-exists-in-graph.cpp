class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        // Step 1: Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]); // undirected
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            if (x == destination)
                return true;
            for (int neighbor : adj[x]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};