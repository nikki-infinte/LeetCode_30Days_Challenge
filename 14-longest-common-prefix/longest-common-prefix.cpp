class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        //sort 
        sort(strs.begin(),strs.end());

        //fetch
        string first=strs[0];
        string last=strs[strs.size()-1];
        int n=min(first.length(),last.length());
        //compare 
        int i=0;
        for( i=0;i<n;i++)
        {
           if(first[i]!=last[i])
           {
            return first.substr(0,i);
           }
        }
         
        return first.substr(0,i);
    }
};