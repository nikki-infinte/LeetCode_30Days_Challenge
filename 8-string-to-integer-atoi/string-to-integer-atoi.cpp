class Solution {
public:
    int myAtoi(string s) {
        

        //skip all leading spaces
        int i=0;
        while(i < s.size() && s[i]==' '){
            i++;
        }

        // check sign
        bool neg = false;
        if(i < s.size() && s[i] == '-'){
            neg=true;
            i++;
        }else if(i < s.size() && s[i] == '+'){
            i++;
        }
       
        while( i < s.size() && s[i]=='0')i++;
        long long ans=0;
        for(int k=i;k<s.size();k++)
        {
            if(isdigit(s[k])){
                int d = s[k] - '0';
                ans = ans *10+d;

                if(neg)
                {
                    if(ans  > (long long)INT_MAX+1) return INT_MIN;
                }else{
                    if(ans > INT_MAX)return INT_MAX;
                }

            }else if( s[k] !='_'){
                break;
            }
        }

        //put the sign 
        if(neg ){
           ans = 0-ans ;
        }
        return ans;
        
    }
};