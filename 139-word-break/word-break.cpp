class Solution {
public:
    unordered_set<string>dict;
    unordered_map<int,bool> dp;
    int n ;

    bool solve(int indx , string s){

        if(indx >= n)return true;
        if(dp.count(indx))return dp[indx];

        if(dict.find(s)!=dict.end())return true;

        for(int len = 1;indx+len<=n;len++){
            string tmp = s.substr(indx,len);
            if(dict.count(tmp) && solve(indx+len , s)){
                return dp[indx] = true;
                }
        }
        return dp[indx] =false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        for(auto a:wordDict){
            dict.insert(a);
        }
        dp.clear();
        return solve(0,s);

    }
};