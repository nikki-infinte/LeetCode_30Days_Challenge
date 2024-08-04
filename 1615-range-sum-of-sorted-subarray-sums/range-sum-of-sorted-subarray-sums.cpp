class Solution {
public:
 int MOD=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
      
       vector<int>tmp;
       for(int i=0;i<n;i++)
       {
        int sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=nums[j];
            tmp.push_back(sum);
        }

       }
        sort(tmp.begin(),tmp.end());

        int res=0;
        for(int i=left-1;i<=right-1;i++)
        {
            res =(res+tmp[i])%MOD;

        }
        return res;

        
    }
};