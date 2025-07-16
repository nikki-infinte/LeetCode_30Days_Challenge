class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto a:piles){
            pq.push(a);
        }

        for(int i=0;i<k && !pq.empty();i++){
            int elm=pq.top();
            pq.pop();
            pq.push(ceil((double)elm/2));
        }

        int ans =0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};