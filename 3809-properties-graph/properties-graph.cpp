class Solution {
public:

    int intersect(vector<int>a,vector<int>b)
    {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int i=0,j=0;
        int n=a.size(),m=b.size();
        int cnt =0;
        while(i<n && j<m)
        {
            if(a[i] == b[j] ){
                if(i > 0 && j>0 && (a[i-1] == a[i] || b[j-1] == b[j])){
                    while( i<n &&a[i] == a[i-1] )i++;
                    while(j<m && b[j] == b[j-1] )j++;
                }else {
                    cnt++;
                    i++;
                    j++;
                }
            }
            else if(a[i] < b[j]) i++;
            else j++;
        }
        return cnt;
    }

    void dfs(vector<int>&visit,unordered_map<int,vector<int>>adj,int a)
    {
        visit[a] = 1;
        for(auto x:adj[a])
        {
            if(visit[x]==0)
            {
                dfs(visit,adj,x);
            }
        }
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        

        unordered_map<int,vector<int>>adj;
        int v = properties.size();

        for(int i=0;i<v;i++)
        {
            for(int j=i+1;j<v;j++)
            {
                if(intersect(properties[i],properties[j]) >=k)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }


        //count using dfs
        int ans =0;
        vector<int>visit(v,0);
        for(int i=0;i<v;i++)
        {
            if(visit[i]==0)
            {
                ans++;
                dfs(visit,adj,i);
            }
        }
        return ans;
    }
};