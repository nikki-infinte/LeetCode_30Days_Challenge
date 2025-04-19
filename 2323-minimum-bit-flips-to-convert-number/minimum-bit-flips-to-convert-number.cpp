class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int num = start ^ goal;
        int cnt=0;
        for(int i=31;i>=0;i--)
        {
            int ith_bit = (num>>i)&1;
            if(ith_bit==1)cnt++;
        }
        return cnt;
    }
};