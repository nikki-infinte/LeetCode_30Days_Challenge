class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>arr;
        int i=0;
        string str ="";
        while(i < s.length())
        {
            if(i+k <= s.length()) 
            { str = s.substr(i,k);
                arr.push_back(str);
                str="";
            }else {
                str = s.substr(i); // Get remaining part
            }
            i+=k;

        }
        

        if(str!="")
        {
           while(str.length()<k)
           {
            str+=fill;
           }
           arr.push_back(str);
        }
        return arr;
    }
};