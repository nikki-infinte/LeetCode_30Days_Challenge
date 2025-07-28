class Solution {
public:
    int maxor ;
    int subset(int currOr ,int indx,vector<int>&nums){
        if(indx >= nums.size()){
            return currOr == maxor;
        }

        int nottake = subset(currOr,indx+1,nums);
        int take = subset(currOr|nums[indx],indx+1,nums);
        return nottake + take;
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        
        for(auto a:nums){
            maxor = maxor | a;
        }
        return subset(0,0,nums);


    }
};