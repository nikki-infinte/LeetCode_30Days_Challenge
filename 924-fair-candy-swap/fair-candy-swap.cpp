class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        
        int sumA = accumulate(a.begin(),a.end(),0);
        int sumB = accumulate(b.begin(),b.end(),0);

        int delta = (sumA - sumB)/2;

        sort(b.begin(),b.end());
        for(int x: a){
            int y=x-delta;
            if(binary_search(b.begin() , b.end() , y)){
                return {x,y};
            }
        }
        return {};
    }
};