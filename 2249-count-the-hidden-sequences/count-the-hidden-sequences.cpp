class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        
        int n = differences.size();
        long long max_ = INT_MIN;
        long long min_ =INT_MAX;
        long long sum=0;

        for(long long i:differences)
        {
            sum+=i;
            max_=max(max_,sum);
            min_=min(min_,sum);

        }

        long long new_low = (lower-min_ < lower) ? lower : lower-min_;
        long long new_up = (upper-max_ > upper) ? upper : upper-max_;
        long long ans = (new_up - new_low ) + 1;
        

        return (ans < 0) ? 0:ans;

    }
};