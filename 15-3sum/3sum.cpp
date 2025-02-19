class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>output;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            int low=i+1;
            int high=n-1;
            while(low<high)
            {
                if(nums[i] + nums [low] + nums[high] < 0)
                {
                    low++;
                }else if(nums[i] + nums [low] + nums[high] > 0)
                {
                    high--;
                }else {
                    output.push_back({ nums[i] , nums [low] , nums[high] });
                    int tmpIndex1 = low;
                    int tmpIndex2 =high ;
                      while(low < high && nums[low] == nums[tmpIndex1]) low++;
                      while(low < high && nums[high] == nums[tmpIndex2]) high--;
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return output;
    }
};