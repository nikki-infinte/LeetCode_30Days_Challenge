class Solution {
public:

    string nextNum(string s)
    {
        string res;
        for(int i=0;i<s.length();i++)
        {
            int cnt =1;
            while( i+1 < s.size() && s[i] == s[i+1])
            {
                ++i,++cnt;
            }
            res += to_string(cnt) + s[i];
        }
        return res;
    }
    string countAndSay(int n) {
        
        string tmp = "1";
        for(int i=1;i<n;i++)
        {
            tmp = nextNum(tmp);
        }
        return tmp;
    }
};