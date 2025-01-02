class Solution {
public:
    int divide(int dividend, int divisor) {
          if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

        long ans=static_cast<long>(dividend/divisor);
        if(ans <= INT_MIN)
        {
            return INT_MIN;
        }
        
       else if(ans >= INT_MAX)
        {
            return INT_MAX;
        }
        return (int)(ans);
    }
};