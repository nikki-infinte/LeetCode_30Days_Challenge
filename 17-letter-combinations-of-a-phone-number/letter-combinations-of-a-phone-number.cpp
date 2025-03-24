class Solution {
public:

    void backtrack(string &digits , int indx , string &curr,unordered_map<int,string>&umap,vector<string>&res)
    {
        if(indx == digits.size())
        {
            res.push_back(curr);
            return ;
        }


        string letters  = umap[digits[indx]-'0'];
        for(char c: letters)
        {
            curr.push_back(c);
            backtrack(digits,indx+1,curr,umap,res);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        

        unordered_map<int,string>umap;
        umap[2] = "abc";
        umap[3] = "def";
        umap[4] = "ghi";
        umap[5] = "jkl";
        umap[6] = "mno";
        umap[7] = "pqrs";
        umap[8] = "tuv";
        umap[9] = "wxyz";

    vector<string>res;
    if(digits.empty())return res;
    string curr="";
    backtrack(digits,0,curr,umap,res);
    return res;


    }
};