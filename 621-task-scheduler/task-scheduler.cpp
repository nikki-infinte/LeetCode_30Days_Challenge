class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        

        unordered_map<char,int>umap;

        for(auto a: tasks)
        {
            umap[a]++;
        }


        priority_queue< pair<int,char>>pq;
        for(auto t : umap)
        {
            pq.push({t.second,t.first});
        }
        int time =0;
        while(!pq.empty())
        {
            int x = 0;
            vector<pair<int,char>>tmp;
            while(x < n+1 && !pq.empty())
            {
                auto elem = pq.top();
                pq.pop();

                if(elem.first > 1)
                {
                    tmp.push_back({elem.first-1,elem.second});
                }
                
                time++;
                x++;
            }
            for (auto a : tmp) {
                pq.push(a);
            }
             if (!pq.empty()) {
                time += (n + 1 - x); // Account for idle time
            }
        }
        return time;
    }
};