class Solution {
public:

    int count( int n)
    {
        if( n ==0 || n==1)
        {
            return n;
        }
        
        if( n % 2 ==0)
        {
            return count(n/2);
        }else{
            return count(n/2)+1;
        }
    }
    vector<int> countBits(int n) {
        

        vector<int>ans;

        for(int i=0;i<=n;i++)
        {
            ans.push_back(count(i));
        }
        return ans;
    }
};