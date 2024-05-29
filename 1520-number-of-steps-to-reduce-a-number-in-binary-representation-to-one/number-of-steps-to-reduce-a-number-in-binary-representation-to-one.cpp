class Solution {
public:
    int numSteps(string s) {
        int res = 0, n = s.size(), r = 0;
        int curBit;
        for(int i = n - 1; i > 0; i--)
        {
            curBit = s[i] - '0';
            curBit += r;
            r = 0; // find remainder 
            if(curBit == 2)
            {
                curBit = 0;
                r = 1;
            }
            if(curBit == 0)
                res += 1;
            else
            {
                res += 2;
                r = 1;
            } 
        }
        return res + r; 
    }
};