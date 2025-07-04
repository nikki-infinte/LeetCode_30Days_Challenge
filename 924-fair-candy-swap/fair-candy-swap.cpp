class Solution {
public:
    vector<int> fairCandySwap(vector<int>& a, vector<int>& b) {
        
        // brute force
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int asum = accumulate(a.begin(),a.end(),0);
        int bsum = accumulate(b.begin(),b.end(),0);

        for(int i=0;i<a.size();i++)
        {
            int as = a[i];
            for(int j=0;j<b.size();j++){
                int state1 = asum -as +b[j];
                int state2 = bsum-b[j] +as;

                if(state1 == state2){
                    return {a[i],b[j]};
                }
            }
        }
        return {-1,-1};
    }
};