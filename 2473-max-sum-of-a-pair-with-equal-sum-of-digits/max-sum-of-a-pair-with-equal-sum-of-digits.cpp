class Solution {
public:
    int sumOfDigit(int number)
    {
        int ans=0;
        while(number > 0)
        {
            ans += number%10;
            number /=10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        
        unordered_map<int,vector<int>>umap;

        for(int i=0;i<nums.size();i++)
        {
            int sumd = sumOfDigit(nums[i]);
            umap[sumd].push_back(i);
        }
        int result =-1;
        // Iterate over each digit sum bucket
        for (auto& [digitSum, indices] : umap) {
            if (indices.size() < 2) continue; // Need at least two numbers

            // Sort indices based on their corresponding numbers in nums (descending order)
            sort(indices.begin(), indices.end(), [&](int a, int b) {
                return nums[a] > nums[b];
            });

            // Take the sum of the two largest numbers
            result = max(result, nums[indices[0]] + nums[indices[1]]);
        }

        return result;
    }
};