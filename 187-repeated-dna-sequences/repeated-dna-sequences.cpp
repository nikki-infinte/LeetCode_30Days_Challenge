class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        int  i=0,j=0;
        unordered_map<string,int>mp;
        int n=s.length();
        string tmp="";

        set<string>vec;
        while(j < n)
        {
            tmp+=s[j];
            if(j-i+1 == 10)
            {
                if(mp.find(tmp)!=mp.end())
                {
                    vec.insert(tmp);
                }
                mp[tmp]++;
                tmp.erase(0,1);
                i++;
            }
            j++;
        }

        vector<string>ans;
        for(auto a:vec)
        {
            ans.push_back(a);
        }
        return ans;
    }
};