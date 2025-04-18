class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int count5 =0,count10 =0,count20 =0;

        if(bills[0] != 5)return false;

        for(int i=0;i<bills.size();i++)
        {
            int b = bills[i];
            
            if(b == 5)count5++;
            else if(b==10)
            {
                if(count5 == 0)return false;
                else {
                    count5 --;
                    count10++;
                }
            }else if(b == 20)
            {
               if (count10 > 0 && count5 > 0) {
                    count10--;
                    count5--;
                    count20++;
                } else if (count5 >= 3) {
                    count5 -= 3;
                    count20++;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};