class Solution {
public:
    int sumOfDigit(int n)
    {
        int x =0;
        while(n > 0)
        {
            int rem = n % 10;
            x += rem;
            n /= 10;
        }
        return x;
    }
    int countLargestGroup(int n) {

        unordered_map<int,vector<int>>map;
        for(int i=1;i<=n;i++)
        {
            int sum =i;
            if( i > 9)
            {
                sum = sumOfDigit(i);
            } 
            map[sum].push_back( i );

        }

        int maxlen= 0;
        for(auto a:map){
            maxlen = max(maxlen ,(int)a.second.size());
        }

        int cnt =0;
        for(auto a:map)
        {
            if(a.second.size() == maxlen)cnt++;
        }
        return cnt;
        
    }
};