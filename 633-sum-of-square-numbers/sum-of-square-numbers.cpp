class Solution {
public:
    bool judgeSquareSum(int c) {

        if(c < 0) return false;

        long i=0;
        long j=(int)sqrt(c);

        while(i<=j)
        {
            long sum=i*i+j*j;
            if(sum==c)
            {
                return true;
            }
            else if(sum <c)
            {
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};