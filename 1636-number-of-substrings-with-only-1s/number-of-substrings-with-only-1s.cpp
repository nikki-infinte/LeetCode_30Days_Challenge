class Solution {
public:
    int MOD = 1e9+7;
    int numSub(string s) {
        int count =0;
        int total =0;

        for(int i=0;i<s.length();i++){
           if(s[i] == '1'){
            count+=1;
            total = (count+total)%MOD;
           }else{
            count =0;
           }
           
        } 
        return total;
    }
};