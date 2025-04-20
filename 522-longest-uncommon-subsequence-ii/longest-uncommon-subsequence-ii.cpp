class Solution {
public:

   bool isSubsequence(string s1,string s2)
    {
        int i=0,j=0;
        while(j<s2.size())
        {
            if(s1[i] == s2[j]){
                i++;
            }
            j++;
        }
        return i == s1.length();
    }
    int findLUSlength(vector<string>& strs) {
        
         int n = strs.size();
        int maxlen = -1;
        for(int i=0;i<n;i++)
        {

       

            bool isUncommon = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j])) {
                    isUncommon = false;
                    break;
                }
            }
            if (isUncommon) {
                maxlen = max(maxlen, (int)strs[i].length());
            }
        }

     
        
        if(maxlen == INT_MIN)return -1;
        return maxlen;
    }
};