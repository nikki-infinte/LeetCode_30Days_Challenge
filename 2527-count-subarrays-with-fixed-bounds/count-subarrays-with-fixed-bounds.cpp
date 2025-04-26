class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
 long long totalCount = 0; 
        int lastInvalid = -1, lastMin = -1, lastMax = -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] <minK || nums[i] > maxK)
            {
                lastInvalid = i;
            }
            
            if(nums[i] ==minK)lastMin = i;
            if(nums[i] == maxK)lastMax =i;

            int validStart = min(lastMin,lastMax);
            totalCount +=max(0,validStart - lastInvalid);
        }
         return totalCount;
    }
};