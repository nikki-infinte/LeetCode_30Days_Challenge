class Solution {
public:

    void DFS(vector<bool>&visit,unordered_map<int,vector<int>>&umap,int node)
    {
        visit[node]=true;
        for(auto it:umap[node])
        {
            if(!visit[it])
            {
                DFS(visit,umap,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<bool>visit(n,false);

        //convertin it into unordered_map 
        unordered_map<int,vector<int>> umap;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    umap[i].push_back(j);
                    umap[j].push_back(i);
                }
            }
        }
        int pro=0;
        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                DFS(visit,umap,i);
                pro++;
            }
        }
        return pro;
    }
};