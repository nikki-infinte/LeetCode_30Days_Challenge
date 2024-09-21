class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        int stair_cnt=0;
        if(n==1){
            return 1;
        }
        if(n==0)
        {
            return 0;
        }
        while(n>=i)
        {
            n-=i;
            i++;
            stair_cnt++;
        }

        return (stair_cnt);
       
    }
};