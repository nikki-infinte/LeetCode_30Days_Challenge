class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        

        int total_product =1;
        int cnt =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0)cnt++;
            else {
                total_product *=nums[i];
            }
        }
        int n=nums.size();
        vector<int>ans(n,0);
        if(cnt > 1){
            return ans;
        }else if(cnt == 1){
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i] == 0)
                {
                    ans[i] = total_product;
                }
            }
        }else if(cnt ==0)
        {
            for(int i=0;i<nums.size();i++)
            {
                ans[i]=total_product / nums[i];
            }
        }


        return ans;
    }
};