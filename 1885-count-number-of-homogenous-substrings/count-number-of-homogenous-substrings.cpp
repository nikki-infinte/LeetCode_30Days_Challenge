class Solution {
public:
    int MOD = 1e9+7;
    int countHomogenous(string s) {
        int n = s.length();
        int count =0;
        int total=0;
        for(int i=0;i<n;i++){
            if(i>0 && s[i] == s[i-1]){
                count+=1;
            }else{
                count=1;
            }
            total=(count+total)%MOD;
        }
        return total;
    }
};