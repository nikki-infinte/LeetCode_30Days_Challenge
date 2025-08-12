class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int>fib;
        fib.push_back(1);
        fib.push_back(1);
        int a = 1, b=1;
      
        int nxt = a+ b;
        while(nxt <= k ){
            fib.push_back(nxt);
            a=b;
            b=nxt;
            nxt = a+b;        
        }

        int i = fib.size() - 1;
        int cnt = 0;
        while ( k > 0 && i > 0) {
           
            if(fib[i] <= k) {

                cnt++;
                k -= fib[i];
            }
            i--;
        }
        return cnt;
    }
};