class Solution {
public:
    int maximumProduct(vector<int>& num) {

        if(num.size() < 3)return -1;
        sort(num.begin(),num.end());
        int n=num.size();
        int maxp = num[n-1] * num[n-2] * num[n-3];
        int maxr = num[n-1] *num[0]*num[1];
        return max(maxr,maxp);

    }
};