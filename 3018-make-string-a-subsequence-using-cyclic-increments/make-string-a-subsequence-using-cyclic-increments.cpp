class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        

        //using two pointer approach
        int i=0;
        int j=0;
        while(i<str1.size() && j<str2.size())
        {
            if(str1[i]==str2[j] || str1[i]+1==str2[j]||(str1[i] == 'z' && str2[j] == 'a'))
            {
                j++;
            }
            i++;
        }
      return j==str2.size();

    }
};