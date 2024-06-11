class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int,int> mp;
        for(auto m:arr1)
        {
            mp[m]++;
        }

        vector<int>ans;
        for(int i=0;i<arr2.size();i++)
        {
            if(mp.find(arr2[i])!=mp.end())
            {
                int count=mp[arr2[i]];
                while(count>0)
                {
                    ans.push_back(arr2[i]);
                    count--;
                }
                if(count==0)
                {
                    mp.erase(arr2[i]);
                }
            }

        }
        for(auto &pair:mp)
        {
            for(int i=0;i<pair.second;i++)
            {
                ans.push_back(pair.first);
            }
        }

        return ans;
    }
};