class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        priority_queue<pair<int,int>>pq;

        int n = stations.size();

        int refuel =0;
        int fuel = startFuel;
        int i=0;
     
        while(fuel < target){


            while(i<n && stations[i][0] <= fuel){
                pq.push({stations[i][1],stations[i][0]});
                i++;
            }
            if(pq.empty())return -1;
            auto topelem = pq.top().first;
            pq.pop();
            refuel ++ ;
            
            fuel += topelem;
        }
       return refuel;
        
    }
};