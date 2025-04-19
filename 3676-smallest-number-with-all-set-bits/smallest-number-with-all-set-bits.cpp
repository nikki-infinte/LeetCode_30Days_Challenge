class Solution {
public:
    int smallestNumber(int n) {
        int mb_position = 0;
        int x =n;
        while( x >0 )
        {
            mb_position++;
           x = x >>1;
        }

        // now number of mb_position i want number of set bits 
        return (1 << mb_position) - 1;
    }
};