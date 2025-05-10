class Solution {
public:

    void generate(vector<string>&res , string& digits ,string curr,int indx,unordered_map<int,string>umap)
    {
        if(indx >= digits.size())
        {
            res.push_back(curr);
            return ;
        }

        string letter = umap[digits[indx]-'0'];
        for(char l:letter)
        {
            curr.push_back(l);
            generate(res,digits,curr,indx+1,umap);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty())return{};
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
        generate(res,digits,"",0,umap);
        return res;
    }
};