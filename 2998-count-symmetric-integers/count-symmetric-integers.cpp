class Solution {
public:

    bool isSymmetric(int x)
    {
        
        string s = to_string(x);
        int  n = s.length();
        if(n == 1 || n % 2 !=0)return false;
      

        int half = n /2;
        int firstpart =0,secondpart =0;

        for(int k = 0; k < half ; k++)
        {
            firstpart +=s[k]-'0';
        }

        for(int j = half ; j < n ;j++)
        {
            secondpart += s[j] - '0';
        }

        return firstpart == secondpart;
    }
    int countSymmetricIntegers(int low, int high) {
        
            int cnt=0;
        for(int i=low ;i <= high ;i++)
        {
            if(isSymmetric(i))
            {
                cout<<i<<" ";
                cnt++;
            }
        }
        return cnt;
    }
};