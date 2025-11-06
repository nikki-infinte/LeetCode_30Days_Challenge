class Solution {
public:
     bool DFS(int u,vector<int>&visit,vector<int>&path,unordered_map<int,vector<int>>&adj){

        if(path[u])return false;
        if(visit[u])return true;

        visit[u]=1;
        path[u]=1;
        for(auto neigh:adj[u]){
            if(visit[neigh] ==0 && DFS(neigh,visit,path,adj)){
                return true;
            }else if(path[neigh] == 1){
                return true;
            }
        }
        path[u]=0;
        return false;

     }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V= graph.size();
        unordered_map<int,vector<int>>adj;
        vector<int>visit(V,0);
        vector<int>path(V,0);

        for(int i=0;i<graph.size();i++){
           for (auto x : graph[i])
                adj[i].push_back(x);
        }
        for(int i=0;i<V;i++){

            if(visit[i]==0){
                DFS(i,visit,path,adj);
            }
        }

        vector<int>ans;
        for(int i=0;i<V;i++){
            if(path[i]==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};