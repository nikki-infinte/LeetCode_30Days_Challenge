class Solution {
public:

    int dfs(int curr, unordered_map<int, vector<int>>& adj, vector<int>& informTime) {
        int maxTime = 0;
        for (int emp : adj[curr]) {
            maxTime = max(maxTime, dfs(emp, adj, informTime));
        }
        return informTime[curr] + maxTime;
    }
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) {
        

        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            
            if(i != headId){
                adj[manager[i]].push_back(i);
            }
        }
        return dfs(headId,adj,informTime);
    }
};