class Solution {
public:

int f(int n)
{
    int sum =0;
    while(n)
    {
        int d = n%10;
        n/=10;
        sum +=d*d;
    }
    return sum;
}
    bool isHappy(int n) {
        

      if( n == 1 || n== 10 || n== 100)return true;
        unordered_set<int>visit;
        while( n!=1 )
        {
            n= f(n);
            if(visit.count(n))
            {
                return false;
            }
            visit.insert(n);
        }

        return n == 1 ? true : false;

    }
};