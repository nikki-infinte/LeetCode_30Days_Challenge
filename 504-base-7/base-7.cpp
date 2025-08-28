class Solution {
public:
    string convertToBase7(int num) {
        const char digits[] ="01234567";
        string ans ="";
        int flag =0;
        if(num < 0){
            num=(-num);
            flag =1 ;
        }

        if(num ==0)return "0";
        while(num > 0){
            ans+=digits[num%7];
            num/=7;

        }
        reverse(ans.begin(),ans.end());
        return (flag ==0)? ans :("-"+ans) ;
    }
};