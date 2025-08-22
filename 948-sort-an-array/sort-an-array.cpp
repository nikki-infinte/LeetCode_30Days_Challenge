class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        for(int i=nums.size()-1;i>=0;i--){
            nums[i] = pq.top();
            pq.pop();
        }
        return nums;
    }
};