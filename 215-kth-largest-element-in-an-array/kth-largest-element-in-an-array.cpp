class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      

     //using opposite heap such that 

     priority_queue<int,vector<int> ,greater<int>>pq;

     for(int i=0;i<nums.size();i++)
     {
        pq.push(nums[i]);

        while(pq.size() >k)
        {
            pq.pop();
        }
     }
    return pq.top();
    }
};