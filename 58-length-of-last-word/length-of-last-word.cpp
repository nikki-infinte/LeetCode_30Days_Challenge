class Solution {
public:
    int lengthOfLastWord(string s) {
        

        int i=s.length()-1;
        while(s[i] == ' ' )
        {
            i--;
        }
        int count=1;
        while(i>=0 && s[i]!=' ')
        {
            count++;
            i--;
            
        }
        return count-1;
    }
};