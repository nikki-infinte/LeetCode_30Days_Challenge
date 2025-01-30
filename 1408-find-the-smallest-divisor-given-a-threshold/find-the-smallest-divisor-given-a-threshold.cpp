class Solution {
public:
    bool possible(vector<int>&nums,int mid,int k)
    {
        int total=0;
        for(int i=0;i<nums.size();i++)
        {
            total += ceil(double(nums[i])/mid);
        }
        return (total <= k);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(possible(nums,mid,threshold))
            {
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
