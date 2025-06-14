class Solution {
public:
    int passThePillow(int n, int time) {
        
        int hop = n-1;
        int round = time / hop;
        int ans =0;

        if( round % 2 == 0)
        {
            ans = (1 + time %(hop) );
        }else{
            ans = (n - time%(hop));
        }
        return ans;
    }
};