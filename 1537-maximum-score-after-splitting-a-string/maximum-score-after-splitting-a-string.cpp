class Solution {
public:
    int maxScore(string s) {
        int total_ones=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                 total_ones++;
            }
           
        }
        int zerocnt=0,ones=0;int bestscore=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]=='0')
            {
                zerocnt++;
            }else if(s[i]=='1')
            {
                ones++;
            }
            int score=zerocnt+(total_ones-ones);
            bestscore=max(bestscore,score);
        }
        return bestscore;
    }
};