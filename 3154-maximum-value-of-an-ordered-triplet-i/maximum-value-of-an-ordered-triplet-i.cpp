class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        

        long long maxAns = LLONG_MIN;

        for(int i=0;i<nums.size();i++)
        {
            //from i+1 consider min as  j and from j+1 consider  k as max
           
            for(int j=i+1;j<nums.size()-1;j++)
            {
                for(int k = j+1;k<nums.size();k++)
                {
                    maxAns=max( (1LL*(nums[i]-nums[j])*nums[k]) ,maxAns ) ;
                }
            }

           
        }
        if(maxAns < 0)return 0;
        return maxAns;
    }
};