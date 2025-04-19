class Solution {
public:
    string bits(int num)
    {
        string ans="";
        for(int i=31 ;i>=0;i--)
        {
            ans+=to_string(( num >> i)& 1);
        }
        return ans;
    }
    int minBitFlips(int start, int goal) {
        string res1 = bits(start);
        string res2 = bits(goal);

        int cnt =0;
        for(int i=0;i<32;i++)
        {
            if(res1[i] !=res2[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};