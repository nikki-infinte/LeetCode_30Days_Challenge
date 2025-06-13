class Solution {
public:

       bool canFormPairs(int p, const vector<int>& nums, int maxDiff) {
        int i = 0;
        int count = 0;

        while (i < nums.size() - 1) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                count++;
                i += 2; // use both i and i+1
            } else {
                i++;
            }
        }

        return count >= p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low = 0, high = nums[ nums.size() - 1] - nums[0];

        int ans = low;
        while( low <= high )
        {
            int mid = ( low + high ) /2 ;

            if( canFormPairs(p,nums,mid) )
            {
                ans = mid ;
                high = mid-1;
            }else{
                low = mid +1 ;
            }
            
        }
        return ans;
    }
};