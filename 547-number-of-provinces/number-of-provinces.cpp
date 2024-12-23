class Solution {
public:
    char visit[200];
    int n;
    int cnt=0;

    void DFS(vector<vector<int>>& isConnected,int node)
    {
        if(visit[node])return ;
        visit[node]=1;
        for(int j=0;j<n;j++)
        {
            if(isConnected[node][j])
            {
                DFS(isConnected,j);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n=isConnected.size();
        for(int i=0;i<n;i++)
        {
            if(!visit[i])
            {
                cnt++;
                DFS(isConnected,i);
            }
        }
        return cnt;
    }
};