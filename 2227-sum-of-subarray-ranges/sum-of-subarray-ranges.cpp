class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>pse(n,-1),nse(n,n);
        stack<int>pst,nst;
        for(int i=0;i<n;i++){
            while(!pst.empty() && nums[pst.top()] >=nums[i]){
                pst.pop();
            }
            if(!pst.empty())pse[i] = pst.top();
            pst.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!nst.empty() && nums[nst.top()] > nums[i]){
             nst.pop();
            }
            if(!nst.empty())nse[i] =nst.top();
            nst.push(i); 
        }


        vector<int>pge(n,-1),nge(n,n);
        stack<int>pgt,ngt;

        //previous greater elem
        for(int i=0;i<n;i++)
        {
            while(!pgt.empty()&& nums[pgt.top()] <= nums[i]){
                pgt.pop();
            }
            if(!pgt.empty())pge[i] = pgt.top();
            pgt.push(i);
        }
        //next greater elem
        for(int i=n-1;i>=0;i--){
            while(!ngt.empty() && nums[ngt.top()] < nums[i]){
                ngt.pop();
            }
            if(!ngt.empty())nge[i]=ngt.top();
            ngt.push(i);
        }

        long long maxi = 0,mini=0;

        for(int i=0;i<n;i++){
            long long contri = (i-pse[i])*1ll*(nse[i]-i);
            mini+=contri*nums[i];


            long long contri2 = (i-pge[i])*1ll*(nge[i]-i);
            maxi+=contri2*nums[i];
        }
        return maxi-mini;

       
    }
};