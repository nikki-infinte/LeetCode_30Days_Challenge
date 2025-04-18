class Solution {
public:
    typedef pair<int,int> P;
    int shortestPathLength(vector<vector<int>>& graph) {
        
        int n = graph.size();
        if( n==0 || n==1)return 0;
        queue<P>q;
        set<P>visit;

        for(int i=0;i<n;i++)
        {
            int mask = (1 << i);
            q.push({i,mask});
            visit.insert({i,mask});
        }

        int allVisited = (1 << n)-1; // pow(2,n)-1
        int path = 0;
        while(!q.empty())
        {
            int s = q.size();
            path++;
            while(s--)
            {
                P curr = q.front();
                q.pop();

                int cnode = curr.first;
                int cmask = curr.second;

                for(auto &aj:graph[cnode])
                {
                   
                    int nxtmsk = (1 << aj) | cmask;
                    if(nxtmsk == allVisited)return path;
                    if(visit.find({aj,nxtmsk}) == visit.end() )
                    {
                     visit.insert({aj,nxtmsk});   
                     q.push({aj,nxtmsk});
                    }


                }

            }
        }
    return -1;

    }
};