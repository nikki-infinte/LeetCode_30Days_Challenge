class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end(),[](const int &a,const int &b){
           string s1 = to_string(a) + to_string(b);
           string s2 = to_string(b)+to_string(a);
           return s1 > s2;
        });

        string res ="";
        for(int i=0;i<nums.size();i++){

            res+=to_string(nums[i]);
        }
        int zero_cnt =0;
 
        for(auto n:nums){
            if(n == 0)zero_cnt++;
        }
        if(zero_cnt == nums.size())return "0";
        
        return res;

    }
};