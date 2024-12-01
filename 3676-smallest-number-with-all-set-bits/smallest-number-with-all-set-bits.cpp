class Solution {
public:
    int smallestNumber(int n) {
    

       int res=0;
       for(int i=0;res<n;i++)
       {
        res=(res << 1)|1;
       }
       return res;
    }
};