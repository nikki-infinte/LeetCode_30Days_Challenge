class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int>prefixmap;

        for(auto const& num:arr1)
        {
            string str1=to_string(num);
            string prefix="";
            for(auto ch:str1)
            {
                prefix+=ch;
                prefixmap[prefix]++;
            }
        }
        int maxi=0;
        for(auto const &num:arr2)
        {
            string str2=to_string(num);
            string p="";
            for(auto const ch:str2)
            {
                p+=ch;
                if(prefixmap.count(p) >0)
                {
                    maxi=max(maxi,(int)p.size());
                }
            }
        }
        return maxi;
    }
};