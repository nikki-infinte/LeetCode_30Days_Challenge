class Solution {
public:

    double pow_fun(double x,long long n1)
    {
        if(n1==0)
        {
            return 1;
        }
        if(n1 % 2==0)
        {
           return pow_fun(x*x,n1/2);
        }else{
           double ans2 = x * pow_fun(x, n1 - 1);
            return ans2;
        }
    }
    double myPow(double x, int n) {
        long long n1=n;
        if (n < 0) {
            return 1 / pow_fun(x, -n1); // Handle negative exponents
        } else {
            return pow_fun(x, n1);
        }
    }
};