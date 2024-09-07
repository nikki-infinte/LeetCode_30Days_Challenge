class Solution {
public:
    void divisor(int n,int &sum)
    {
         vector<int> divisors;
        int sqrt_n = sqrt(n);
        for (int i = 1; i <= sqrt_n; ++i) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i) {
                    divisors.push_back(n / i);
                }
            }
        }
        if (divisors.size() == 4) {
            sum += accumulate(divisors.begin(), divisors.end(), 0);
        }
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            divisor(nums[i],sum);
        }
        return sum;
    }
};