class Solution {
public:
    bool checkValidString(string s) {
        int minrange=0;
        int maxrange=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i] =='(')
            {
                minrange+=1;
                maxrange+=1;
            }else if(s[i]==')')
            {
                minrange -= 1;
                maxrange -= 1;
            }

            else{
                minrange -=1;
                maxrange +=1;

            }

            if(minrange<0){
                minrange=0;
            }
            if(maxrange<0)
            {
                return false;
            }
        }
        return(minrange==0);
    }
};