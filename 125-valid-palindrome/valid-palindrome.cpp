class Solution {
public:
    bool isPalindrome(string s) {
        string newstr="";
        for(int i=0;i<s.length();i++)
        {
            if(isalpha(s[i]))
            {
                newstr+=tolower(s[i]);
            }else if(isdigit(s[i]))
            {
               newstr+=s[i];
            }
        }

        int low=0;
        int high=newstr.size()-1;

        while(low<=high)
        {
            if(newstr[low]!=newstr[high])
            {
                return false;
            }
            else{
                low++;
                high--;
            }

        }
        return true;
    }
};