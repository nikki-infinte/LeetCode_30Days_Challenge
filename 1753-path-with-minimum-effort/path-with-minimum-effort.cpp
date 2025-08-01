class Solution {
public:
    typedef pair<int, pair<int,int>> p;

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<p,vector<p> ,greater<p>>pq;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        dist[0][0]=0;
        pq.push({0, {0,0}});

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) return diff;

            for(int i=0; i<4; i++)
            {
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >= 0 && newc >=0 && newr < n && newc < m)
                {
                    int newEff = max(abs(heights[row][col] - heights[newr][newc]) , diff);

                    if(newEff < dist[newr][newc])
                    {
                        dist[newr][newc] = newEff;
                        pq.push({newEff, {newr, newc}});  
                    }
                }
            }
        }
        return 0; 
        
    }
};
