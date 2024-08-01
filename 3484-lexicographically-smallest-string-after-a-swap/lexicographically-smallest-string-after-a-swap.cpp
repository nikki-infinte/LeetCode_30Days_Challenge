class Solution {
public:
    string swap(int i,int e,string s )
    {
        char ch=s[i];
        s[i]=s[e];
        s[e]=ch;
        return s;
    }
    string getSmallestString(string s) {

        string org=s;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]%2==s[i+1]%2)
            {
                //swap
                string change=swap(i,i+1,s);
                if(org > change)
                {
                    return change;
                }
            }
        }
        return s;
    }
};