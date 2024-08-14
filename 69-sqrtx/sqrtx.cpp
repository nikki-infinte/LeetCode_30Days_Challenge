class Solution {
public:
    int mySqrt(int x) {
        
        //using binary search
    if(x==0||x==1)
    {
        return x;
    }
        int low=2;
        int high=x/2;
        int mid;

        while(low<=high)
        {
             mid = low + (high - low) / 2;
              long long squared = static_cast<long long>(mid) * mid;
            if(squared==x)
            {
                return mid;
            }

            if(squared> x)
            {
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return high;
    }
};