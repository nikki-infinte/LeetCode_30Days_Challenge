class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>d;
        int n = nums.size();

        for(int i=0;i<n;i++){

            //step 1: 
            while(!d.empty() && d.front() <= i-k ){
                d.pop_front();
            }

            //step 2:
            while(!d.empty() && nums[i] >= nums[d.back()]){
                d.pop_back();
            }
            //step 3: 
            d.push_back(i);
            if(i >=k-1){
                ans.push_back(nums[d.front()]);
            }
            
        }
        return ans;
    }
};