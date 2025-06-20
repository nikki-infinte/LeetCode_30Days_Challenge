class Solution {
public:
    bool areNumbersAscending(string s) {
        int prev = 0;
        int i = 0;
        
        while (i < s.size()) {
            if (isdigit(s[i])) {
                int num = s[i] - '0';
                
                while (i + 1 < s.size() && isdigit(s[i + 1])) {
                    num = num * 10 + (s[i + 1] - '0');
                    i++;
                }
                
                if (num <= prev) return false;
                prev = num;
            }
            i++;
        }
        
        return true;
    }
};
