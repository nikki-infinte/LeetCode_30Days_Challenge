class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int>stk;
        for(int i=0;i<=logs.size()-1;i++)
        {

            if(logs[i]=="../")
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
            }else if(logs[i]!="./")
            {
                stk.push(i);
            }

        }
        return stk.size();
    }
};