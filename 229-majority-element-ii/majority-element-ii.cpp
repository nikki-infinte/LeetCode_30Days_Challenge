class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int>ans;
        int cnt1 = 0 ,cnt2=0;
        int elem=INT_MIN ,elem2=INT_MIN;

        for(int i=0;i<nums.size();i++)
        {

            if(cnt1==0 && nums[i]!=elem2)
            {
                cnt1=1;
                elem=nums[i];
            }else if(cnt2==0 && nums[i]!=elem)
            {
                cnt2=1;
                elem2=nums[i];
            }else if(elem==nums[i]){
                cnt1++;
            }else if(elem2 == nums[i])
            {
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }


        //verify both elem 1 and elem 2 
        int vcount=0,vcnt=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==elem )
            {
                vcount++;
            }else if(nums[i]==elem2)
            {
                vcnt++;
            }
        }
        if(vcnt > (n/3))
        {
            ans.push_back(elem2);
        }
        if(vcount > (n/3))
        {
            ans.push_back(elem);
        }
        return ans;
    }
};