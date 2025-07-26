class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long findPower(long long a, long long b) {
        if (b == 0) return 1;
        long long half = findPower(a, b / 2);
        long long res = (half * half) % MOD;
        if (b % 2 == 1) {
            res = (res * a) % MOD;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long power5 = findPower(5, even);
        long long power4 = findPower(4, odd);

        return (int)((power5 * power4) % MOD);
    }
};
