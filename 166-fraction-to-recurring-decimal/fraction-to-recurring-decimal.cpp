class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string ans;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) ans += '-';

        // Use long long before taking abs
        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        // Integer part
        long long q = n / d;
        long long r = n % d;
        ans += to_string(q);

        // If there's no remainder, return result
        if (r == 0) return ans;

        // Decimal part
        ans += '.';
        unordered_map<long long, int> mp;

        while (r != 0) {
            if (mp.find(r) != mp.end()) {
                int pos = mp[r];
                ans.insert(pos, "(");
                ans += ')';
                break;
            }
            mp[r] = ans.length();
            r *= 10;
            q = r / d;
            r = r % d;
            ans += to_string(q);
        }

        return ans;
    }
};
