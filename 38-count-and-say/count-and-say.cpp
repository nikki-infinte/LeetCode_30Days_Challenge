class Solution {
public:
    string Recursion(string& str , int n)
    {
        if(n==0)return str;

        int count =1 ;
        string update="";
        
         for(int i=1;i<str.size();i++)
             {
                 if(str[i-1] == str[i])count++;
                 else{
                     update+=to_string(count);
                     update+=str[i-1];
                     count =1 ;
                 }
             }
        update += to_string(count);
        update += str[str.size()-1];
       return  Recursion(update,n-1);
    }
    string countAndSay(int n) {
        string str = "1";
      return  Recursion(str,n-1);
    
        
    }
};