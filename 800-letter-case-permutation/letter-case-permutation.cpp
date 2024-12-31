class Solution {
public:
vector<string>ans;
    void letter(string out,string input,int index)
    {
        if(index==input.size())
        {
            ans.push_back(out);
            return ;
        }

        if(input[index] >='0' && input[index]<='9')
        {
            out+=input[index];
            letter(out,input,index+1);
        }
        else{
          
          //consider lower case
          string c1=out;
          c1.push_back(tolower(input[index]));
          letter(c1,input,index+1);


          //case 2
          string c2=out;
          c2.push_back(toupper(input[index]));
          letter(c2,input,index+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        letter("",s,0);
        return ans;
    }
};