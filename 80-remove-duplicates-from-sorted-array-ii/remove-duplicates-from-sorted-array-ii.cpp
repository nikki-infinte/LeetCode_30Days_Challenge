class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //brute force
        int n = nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        vector<int>tmp;
        for(auto a:mp)
        {
            if(a.second >= 2){
                tmp.push_back(a.first);
                tmp.push_back(a.first);

                a.second = a.second -2;
               
            }
            else if(a.second == 1)
            {
                tmp.push_back(a.first);
                a.second = a.second -2;
               
            }
        }

        int ans =tmp.size();
       for(auto a:mp)
       {
        int i= a.second;
        while(i--)
        {
            tmp.push_back(a.first);
        }
        
       }

       nums = tmp;
        return ans;
    }
};