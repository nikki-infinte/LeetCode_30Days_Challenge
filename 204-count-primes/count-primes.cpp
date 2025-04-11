class Solution {
public:
int N;
vector<bool>vec;

    void seive()
    {
        for(int i=2;i*i<N;i++)
        {
            if(vec[i] == true)
            {
                for(int j=i*i;j<N;j+=i)
                {
                    vec[j] = false;
                }
            }
        }
    }

    int countPrimes(int n) {

        
    if(n <= 1)return 0;


        N = n+1;
        int cnt=0;
        vec.resize(N,true);
        vec[0]=vec[1] = false;
        seive();

     for(int i=0;i<n;i++)
     {
        if(vec[i] ==true)
        {
            cnt++;
        }
     }   

     return cnt;
    }
};