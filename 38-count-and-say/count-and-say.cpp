class Solution {
public:

    string countHere(string s , int times)
    {
        if(times == 0 )
        {
            return s;
        }

        int i=0;
       
        string new_str="";
        while(i< s.length())
        {
             int count=1;
            while( i+1 <s.length() &&s[i]==s[i+1] )
            {
                count++;
                i++;
            }
           new_str += to_string(count) + s[i]; // Append count and character
            i++;
          
        }
         

        return countHere(new_str , times-1);
    }
    string countAndSay(int n) {
       return  countHere("1",n-1);
    }
};