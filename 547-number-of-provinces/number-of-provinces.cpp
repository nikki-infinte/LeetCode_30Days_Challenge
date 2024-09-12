class Solution {
public:

    void DFS(vector<int>&visit,vector<int>adj[],int u)
    {
        visit[u]=1;
        for(auto &a:adj[u]){
            if(!visit[a])
            {
                DFS(visit,adj,a);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        vector<int>visit(n,0);
        int no_pro=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                DFS(visit,adj,i);
                no_pro++;
            }
        }

        return no_pro;
    }
};