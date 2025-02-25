class Solution {
public:
int M =1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();


        vector<int>psum(n,0);
        psum[0]=arr[0];

      
        for(int i=1;i<n;i++)
        {
            psum[i]=psum[i-1]+arr[i];
        }
          
        int evencnt =1,oddcnt =0;
        int cnt =0;
        for(int  i=0;i<n;i++)
        {
            if(psum[i]%2 == 0){
                cnt = (cnt+oddcnt)%M;
                evencnt++;
            }else{
                cnt = (cnt +evencnt )%M;
                oddcnt++;
            }
        }
return cnt;
    }
};