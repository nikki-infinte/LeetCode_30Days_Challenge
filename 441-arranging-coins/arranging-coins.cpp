class Solution {
public:
    int arrangeCoins(int n) {
        
        int i=1;
        while(n>=0)
        {
            n=n-i;
            i++;
        }
        return i-2;
    }
};