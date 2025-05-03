class Solution {
public:
    string pushDominoes(string dominoes) {
        string dom ="L" + dominoes + "R";
        int n = dom.size();

        string res = dom;
        int j=0;
        for(int k=1;k<n;++k)
        {
            if(dom[k] =='.')continue;

            //process segment
            if( k-j > 1){
                 if (dom[j] == 'L' && dom[k] == 'L') {
             // Case 1: L....L → LLLLL
                    for (int x = j + 1; x < k; ++x)
                        res[x] = 'L';       
                 }
                 else if(dom[j] == 'R' && dom[k] == 'R')
                 {
                    //case 2 : R....R
                    for(int x= j+1;x<k;++x)
                    {
                        res[x] ='R';
                    }
                 }else if(dom[j] == 'R' && dom[k] == 'L')
                 {
                     // Case 4: R....L → R...L split
                    int l= j+1,r =k-1;
                    while( l < r)
                    {
                        res[l++] = 'R';
                        res[r--] ='L';
                    }
                 }
           

            }
             j = k;
        }

        return res.substr(1,n-2);
    }
};