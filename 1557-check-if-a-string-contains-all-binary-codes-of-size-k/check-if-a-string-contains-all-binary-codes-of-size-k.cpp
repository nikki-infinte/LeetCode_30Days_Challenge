class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>res;
        int n =pow(2,k);
        if( k > s.size())return false;

        for(int i=0;i<=s.size()-k;i++){
            res.insert(s.substr(i,k));
            if(res.size() == n) return true;
        }

        return false;
    }
};