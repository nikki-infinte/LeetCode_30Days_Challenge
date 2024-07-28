class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    //optimal

    unordered_map<int,bool>mp;
    int longest=0;
    for(auto &n:nums)
    {
        mp[n]=false;
    }

        for(int n:nums)
        {
            int curr=1;
            mp[n]=true;

            //nxt
            int nxt=n+1;
            while(mp.find(nxt)!=mp.end()  && mp[nxt]==false)
            {
                curr++;
                mp[nxt]=true;
                nxt++;
            }

            int prev=n-1;
            while(mp.find(prev)!=mp.end() && mp[prev]==false)
            {
                curr++;
                mp[prev]=true;
                prev--;
            }

            longest=max(longest,curr);
        }
        return longest;
    }
};