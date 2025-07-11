class Solution {
public:
    bool DFS(vector<vector<int>>&adj, vector<int>& color, int node,
             int currColor) {
         color[node] = currColor;
        for(auto neighbor : adj[node]){
            if(color[neighbor] == currColor) return false;
            if(color[neighbor] == -1){
                if(!DFS(adj, color, neighbor, !currColor)){
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

         vector<vector<int>> adj(n+1);  // 1-based indexing

        for(auto &d : dislikes){
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (!DFS(adj, color, i, 0)) {
                    return false;
                }
            }
        }

        return true;
    }
};