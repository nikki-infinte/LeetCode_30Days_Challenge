class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int max_di=0;
        for(int i=0;i<houses.size();i++){
            int min_di = INT_MAX;
            for(int j=0;j<heaters.size();j++){
                 min_di = min(abs(heaters[j] - houses[i]), min_di);
            }
            max_di =max(max_di,min_di);
        }
        return max_di;
    }
};