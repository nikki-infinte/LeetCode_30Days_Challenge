class Solution {
public:
    bool checkPowersOfThree(int n) {
        

        while ( n > 0)
        {
            if(n % 3 ==2 )return false;
            n/=3;
        }
        return true;
    //  //brute force 
    //  int i=0,j=1;
    // long long int val = 0;
    // while(val != n && i<15 && j<15 ){
      

    //     val += pow(3,i)+pow(3,j);

    //     if(val == n)return true;

    //     if(val > n )
    //     {
    //         val -= pow(3,i);
    //         i++;
    //     }else if( val < n)
    //     {
    //         j++;
    //     }else{
    //         return true;
    //     }

    // }
    // return false;

    }
};