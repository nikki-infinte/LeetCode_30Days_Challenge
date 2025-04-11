class Solution {
public:

    int convert10toK(int n,int k)
    {
        string res = "";
        while(n  > 0)
        {
            int rem = n % k;
            res+=to_string(rem);
            n /= k;
        }
        reverse(res.begin(),res.end());
        return stoi(res);
    }

    int sumOfDigit(int n)
    {
        int x=0;
        while(n > 0)
        {
            x+=n%10;
            n/=10;
        }
        return x;
    }

   
    int sumBase(int n, int k) {
        int c = convert10toK(n,k);
        int sum = sumOfDigit(c);
       // int ans = convertktoDecimal(sum,k);

        return sum;

    }
};