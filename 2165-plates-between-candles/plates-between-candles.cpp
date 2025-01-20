class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int>prefix(n,0);

        for(int i=0;i<n;i++)
        {
           prefix[i]=(s[i]=='*' ? 1 : 0) +(i > 0 ? prefix[i-1]: 0);

        }

        vector<int>left(n,-1);
        for(int i=0 , lastleft=-1;i<n;i++)
        {
            if(s[i]=='|')
            {
                lastleft=i;

            }
            left[i]=lastleft;
        }

        vector<int>right(n,-1);
        for(int i=n-1,lastright=-1; i>=0 ; i-- )
        {
            if(s[i]=='|'){
                lastright=i;
            }
            right[i]=lastright;
        }

        vector<int>res;
        for(auto a: queries)
        {
            int start=a[0];
            int end=a[1];

            int  l= right[start];
            int r= left[end];

            if(l!=-1 && r != -1 && l < r)
            {
                res.push_back( prefix[r] - prefix[l] );
            }else{
                res.push_back(0);
            }
        }
        return res;
    }
};