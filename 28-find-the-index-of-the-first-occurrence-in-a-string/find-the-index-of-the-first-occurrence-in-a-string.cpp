class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=needle.size();
        if(haystack.find(needle)!=string::npos)
        {
            return haystack.find(needle);
        }
        return -1;

    }
};