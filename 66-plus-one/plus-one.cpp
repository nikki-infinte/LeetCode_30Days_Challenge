class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int n = digits.size();
        n--;
        
        while( n > 0)
        {
            if(digits[n] < 9)
            {
                digits[n] ++;
                return digits;
            }else if(digits[n] == 9){
                digits[n] = 0;

            }
            n--;


        }
        if( n == 0 && digits[n] == 9){
            digits[n] =0;
            digits.insert(digits.begin(),1);
        }else if(n == 0 && digits[n] < 9)
        {
            digits[n] ++;
        }
        return digits;
    }
};