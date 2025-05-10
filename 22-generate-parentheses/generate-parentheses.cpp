class Solution {
public:

    void generate(int open ,int close , string tmp ,vector<string>&res)
    {
        if(open ==0 && close==0){
            res.push_back(tmp);
            return;
        }

        if(open > 0){
            generate(open-1,close,tmp+'(',res);
        }

        if(close > open){
            generate(open,close-1,tmp+')',res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        generate(n,n,"",res);
        return res;
    }
};