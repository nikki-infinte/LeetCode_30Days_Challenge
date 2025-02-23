class Solution {
public:
    bool hasSameDigits(string s) {
        
       //first operation 

       string new_str="";
       for(int i=0;i<s.length()-1;i++)
       {
        new_str.push_back((s[i]-'0'+s[i+1]-'0')%10);
       }

       while(new_str.length() >2)
       {
        string temp="";
        for(int i=0;i<new_str.size()-1;i++){
            temp.push_back((new_str[i]-'0'+new_str[i+1]-'0')%10);
        }
        new_str=temp;
       }

       return new_str[0] == new_str[1];
        
    }
};