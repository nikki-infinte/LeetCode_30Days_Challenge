class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<bool>placed(n,false);
        int cnt =0;
        for(int i=0;i<n;i++){
            int elem = fruits[i];
            for(int j=0;j<n;j++){
                if(placed[j] == false && baskets[j] >= elem){
                    placed[j] = true;
                    cnt++;
                    break;
                }
            }
        }
        return  n - cnt;
    }
};