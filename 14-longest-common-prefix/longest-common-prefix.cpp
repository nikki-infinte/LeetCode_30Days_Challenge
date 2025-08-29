class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        sort(strs.begin(),strs.end());
        if(strs[0] == "")return "";
        string compare = strs[0] , compare2 = strs[strs.size()-1];
        
        int i=0;
        while(i<compare.size() && compare[i] == compare2[i]){
            i++;
        }
        return compare.substr(0,i);
    }
};