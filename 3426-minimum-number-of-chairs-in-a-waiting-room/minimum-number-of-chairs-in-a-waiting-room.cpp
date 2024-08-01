class Solution {
public:
    int minimumChairs(string s) {
        int person=0;
        int chair=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='E')
            {
                if(chair<=person)
                {
                    chair++;
                    person++;
                }
                if(chair > person)
                {
                    person++;
                }
            }else if(s[i]=='L')
            {
                person--;
            }
        }
        return chair;
    }
};