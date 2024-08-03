class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto a:arr)
        {
            mp[a]++;
        }

        if(target.size()!=arr.size())
        {
            return false;
        }
        for(int i=0;i<target.size();i++)
        {
            if(mp.find(target[i])==mp.end())
            {
                return false;
            }else if(mp.find(target[i])!=mp.end())
            {
                mp[target[i]]--;
                if(mp[target[i]]==0)
                {
                    mp.erase(target[i]);
                }
            }
            
        }
        return (mp.empty()) ?true:false;
    }
};