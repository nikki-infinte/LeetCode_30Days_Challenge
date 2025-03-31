class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        if( k == 1)return 0;

        vector<int>adj_sum;

        for(size_t i=0;i<weights.size()-1;i++)
        {
            adj_sum.push_back(weights[i]+weights[i+1]);
        }

        sort(adj_sum.begin(),adj_sum.end());

        long long minScore  =accumulate(adj_sum.begin(),adj_sum.begin()+(k-1),0LL);
        long long maxScore = accumulate(adj_sum.end()-(k-1),adj_sum.end(),0LL);

        return maxScore - minScore;
    }
};