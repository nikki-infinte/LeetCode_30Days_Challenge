class Solution {
public:

    int myAtoi(string s) {
        
        int i = 0;
        int n = s.length();
        
        // Trim leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        // Check for sign
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        
        long ans = 0;
        while (i < n) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + (s[i] - '0');
                if (ans > INT_MAX) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
                i++;
            } else {
                break;
            }
        }
        return static_cast<int>(ans * sign);
    }
};