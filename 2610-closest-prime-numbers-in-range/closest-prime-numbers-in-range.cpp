class Solution {
public: 
    vector<bool> sieve(int n)
    {
        vector<bool> isPrime(n+1 , true);
        isPrime[0] = isPrime[1] = false;

        for(int i=2;i*i<=n ;i++)
        {
            if(isPrime[i])
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    isPrime[j] =false;
                }
            }
        }
        return isPrime;
    }
    vector<int> closestPrimes(int left, int right) {
          vector<bool> isPrime = sieve(right);
        vector<int>vec;
        for(int i=left;i<=right;i++)
        {
           if(isPrime[i])
           {
            vec.push_back(i);
           }
        }
     
        if(vec.size() < 2)
        {
            return {-1,-1};
        }
     sort( vec.begin(),vec.end());

    priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>> > ,greater<pair<int,pair<int,int>>>>pq;
    for(int i=0;i<vec.size()-1;i++)
    {

        pq.push({abs( vec[i] - vec[i+1] ),{vec[i] , vec[i+1]}});
    }

    if(!pq.empty())
    {
        return { pq.top().second.first ,pq.top().second.second} ;
    }
     return {-1,-1};
    }
};