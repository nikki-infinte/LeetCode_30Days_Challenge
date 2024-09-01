class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        int a1=(c1[0]-'a')+1;
        int a2=c1[1]-'0';
        int b1=(c2[0]-'a')+1;
        int b2=c2[1]-'0';

        int sum1=a1+a2;
        int sum2=b1+b2;
        return (sum1%2==sum2%2);
    }
};