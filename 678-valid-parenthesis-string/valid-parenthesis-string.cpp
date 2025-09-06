class Solution {
public:
    int dp[101][101];
    bool solve(int indx,int open ,string s){

        //base case
        if(indx >= s.length())return open==0;
        
        if(dp[indx][open]!=-1)return dp[indx][open];
        //recursion condition
        bool isValid = false;
        if(s[indx] == '('){
            isValid |= solve(indx+1,open+1,s);
        }else if(s[indx] == '*'){
            isValid |= solve(indx+1,open,s);
            isValid |= solve(indx+1,open+1,s);
            if(open > 0){
                isValid |= solve(indx+1,open-1,s);
            }
        }else if(open > 0){
             isValid |= solve(indx+1,open-1,s);
        }
        if(isValid)dp[indx][open] = 1;
        else dp[indx][open] = 0;

        return isValid;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};