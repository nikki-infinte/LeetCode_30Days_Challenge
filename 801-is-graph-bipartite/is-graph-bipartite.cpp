class Solution {
public:
    bool DFS(unordered_map<int, vector<int>> umap, int node, vector<int>& color,
             int currColor) {
        color[node] = currColor;
        for (auto v : umap[node]) {

            if (color[v] == currColor) {
                return false;
            }
            if (color[v] == -1) {
                if (DFS(umap, v, color, !currColor) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        // adjacency list
        unordered_map<int, vector<int>> umap;

        for (int i = 0; i < v; i++) {
            if (graph[i].size() == 0)
                continue;
            for (int j = 0; j < graph[i].size(); j++) {
                umap[i].push_back(graph[i][j]);
            }
        }

        vector<int> color(v, -1);
        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (!DFS(umap, i, color, 0)) {
                    return false;
                }
            }
        }
        return true;
    }
};