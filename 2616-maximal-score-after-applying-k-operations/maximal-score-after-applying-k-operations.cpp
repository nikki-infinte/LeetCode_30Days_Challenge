class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {

        int n = nums.size();
      priority_queue<int> pq;

        for(auto a:nums)
        {
            pq.push(a);
        }

        long long  score=0;
        while ( k --)
        {
            int t =pq.top();
            pq.pop();
            score+=t;
            if(t %3 ==0)
            {
                pq.push(t /3);
            }
            else {
                pq.push((t /3)+1);
            }
        }
        return score;
    }
};