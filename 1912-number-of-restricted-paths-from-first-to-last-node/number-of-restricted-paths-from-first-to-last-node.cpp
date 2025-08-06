class Solution {
public:
    const int MOD = 1e9 + 7;


    int DFS(int currNode ,vector<vector<pair<int,int>>>& graph , vector<int>&dist, vector<int>&dp){

        if(currNode == dist.size()-1)return 1;//reached to node n
        if(dp[currNode]!=-1)return dp[currNode];

        int ways =0;
        for(auto a: graph[currNode]){
            auto nei = a.first;
      
            if(dist[currNode] > dist[nei]){
                  ways = (ways + DFS(nei, graph, dist, dp)) % MOD;
            }
        }
        return dp[currNode] = ways;
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        

        vector<vector<pair<int,int>>> graph(n+1);
for(auto& e : edges){
    int u = e[0], v = e[1], w = e[2];
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
}

       //step 1 : Djikstra from node n

       vector<int>dist(n+1,INT_MAX);
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

      dist[n]=0;
      pq.push({0,n});

      while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();

        if(d  > dist[u])continue;

        for(auto [v,w] : graph[u]){
            
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v}); 
            }
        }
      }


      //DFS from node 1
      vector<int>dp(n+1,-1);
      return DFS(1,graph,dist,dp);
    }
};