class Solution {
public:
    bool judgeCircle(string moves) {
        int i=0,j=0;
        for(int k=0;k<moves.size();k++)
        {
            if(moves[k]=='U') i=i-1;
            else if(moves[k]=='D') i=i+1;
            else if(moves[k]=='L')j=j-1;
            else if(moves[k]=='R')j=j+1;
        }

       return (i==0 && j==0);
    }
};