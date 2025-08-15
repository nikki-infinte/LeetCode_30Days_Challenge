class Solution {
public:
    int reverseBits(int n) {
        int left =0, right =31;

        while(left< right ){

            //extract the bits 
            int l =(n>>left)&1;
            int r = (n>>right)&1;
         
            if( l != r){
                //toggle if they are different
                n^=(1<<left);
                n^=(1<<right);
            }
         
         left++;
         right--;
        }
        return n;
    }

};