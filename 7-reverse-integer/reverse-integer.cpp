class Solution {
public:
    int reverse(int x) {
         int new_num=0;
        
           
            while(x)
            {
                int rem=x%10;
                //overflow check under flow check
                if((new_num > INT_MAX/10) || (new_num < INT_MIN/10))
                {
                    return 0;
                }
                new_num=new_num*10+rem;
                x=x/10;
            }

        
        return new_num;
    }
};