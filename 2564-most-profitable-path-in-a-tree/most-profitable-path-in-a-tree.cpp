class Solution {
public:
unordered_map<int,vector<int>>umap;
unordered_map<int,int>BobMap;
int aliceIncome;
    bool DFSBob(int curr , int t,vector<bool>&visit)
    {
        visit[curr]=true;
        BobMap[curr]=t;

        if(curr == 0)return true;

        for(auto &angbr : umap[curr])
        {
            if(!visit[angbr])
            {
                if( DFSBob(angbr,t+1,visit)==true)
                {
                    return true;
                }
            }
        }

        BobMap.erase(curr);
        return false;

    }

    void DFSAlice(int curr , int t, int income ,vector<bool>&visited , vector<int>&amount)
    {
         visited[curr]=true;
        if(BobMap.find(curr) == BobMap.end() || t < BobMap[curr])
        {
            income+=amount[curr];
        }else if( t == BobMap[curr])
        {
            income +=amount[curr]/2;
        }

        if(umap[curr].size() == 1 && curr!=0)
        {
            aliceIncome = max( aliceIncome,income);
        }

        for(auto &agbr : umap[curr])
        {
            if(!visited[agbr])
            {
                DFSAlice(agbr,t+1,income,visited,amount);
            }
        }

    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n =amount.size();
         aliceIncome = INT_MIN;
        for(vector<int>&e :edges )
        {
            int u = e[0];
            int v = e[1];
            umap[u].push_back(v);
            umap[v].push_back(u);


        }

        //DFS for bob
        int time = 0;
        vector<bool>visit(n,false);
        DFSBob(bob,time,visit);

        int income =0;
        visit.assign(n,false);
        DFSAlice(0,0,income,visit,amount);
        return aliceIncome;
            
    }
};