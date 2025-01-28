class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
       
        int chara=coordinate1[0]-'a'+1;
        int value=coordinate1[1];

        int chara1 = coordinate2[0]-'a'+1;
        int value1=coordinate2[1];

        if( (chara % 2 && chara1 % 2 ) || (chara%2==0 && chara1 % 2 ==0) )
        {
            if( value % 2 == 0 && value1 % 2 ==0 )
            {
                return true;
            }else if( (value % 2 != 0 && value1 % 2 !=0 ) )
            {
                return true;
            }else{
                return false;
            }
        }else {
             if( value % 2 == 0 && value1 % 2 ==0 )
            {
                return false;
            }else if( (value % 2 != 0 && value1 % 2 !=0 ) )
            {
                return false;
            }else{
                return true;
            }
        }
    }
};