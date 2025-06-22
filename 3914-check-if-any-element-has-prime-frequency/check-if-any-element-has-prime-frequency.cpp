class Solution {
public:

    bool is_prime(int z)
    {

        if(z < 2)return false;
        if(z == 2)return true;

        for(int i = 2 ;i*i <= z ;i++ )
        {
            if( z % i ==0)return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>umap;

        for(auto a:nums)
        {
            umap[a]++;
        }


        for(int i=0;i<nums.size();i++)
        {
            if(is_prime(umap[nums[i]]))return true;
        }
        return false;
    }
};