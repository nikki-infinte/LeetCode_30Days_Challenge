class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int seat = 0, maxDist = 0;

        int prev = -1;
        vector<int> vacant;
        int n = seats.size();
        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                vacant.push_back(i);
            }
        }
        if (vacant.size() == 1) {
           
                maxDist = max(maxDist, vacant[0] - 0);
                maxDist = max(maxDist, n - 1 - vacant.back());
            
        }
       
        for (auto s : vacant) {
            if (prev != -1) {
                int d = (s - prev) / 2;
                if (d > maxDist) {
                    maxDist = d;
                    seat = prev + d;
                }
            }
            prev = s;
        }
         if(vacant[0] != 0){
            if( vacant[0] - 0 > maxDist){
                maxDist = max(maxDist,vacant[0]);
            }
        }

        //gap by last index
        int x= vacant.size()-1;
        if(vacant[x] != n ){
            maxDist = max(maxDist,n-vacant[x]-1);
        }
        return maxDist;
    }
};