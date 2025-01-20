class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int elem;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                elem=nums[i];
                cnt=1;
            }
           else if(elem==nums[i])
           {
            cnt++;
           }else{
            cnt--;
           }
           
        }

        int vcount=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==elem)
            {
                vcount++;
            }
        }
        if(vcount > (n/3)) 
        {
            return elem;
        }
        return -1;
    }
};