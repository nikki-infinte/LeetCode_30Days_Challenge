class Solution {
public:


    bool isPossible(vector<int>bloom ,int day,int m,int k)
    {       int cnt =0;
            int no_p = 0;
            for(int i=0;i<bloom.size();i++)
            {
                if(bloom[i] <= day){
                    cnt++;
                }else {
                    no_p += (cnt / k);
                    cnt=0;

                }
                if(no_p >= m)return true;
            }
             no_p += cnt / k;
             if(no_p >= m)return true;

        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
     

        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());

        int ans =-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(isPossible(bloomDay,mid,m,k))
            {
                ans = mid;
                high=mid-1;
            }else{
                low = mid+1;
            }
        }
    return ans;

    }
};