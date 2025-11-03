class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int prev =0;
        int time =0;
        for(int i=1;i<neededTime.size();i++){
            if(colors[i]==colors[i-1]){
                time+=min(neededTime[prev],neededTime[i]);
                if(neededTime[i] > neededTime[prev]){
                    prev = i;
                }
            }else{
                prev =i;
            }
        }
        return time;
    }
};