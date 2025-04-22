class Solution {
public:
 // function to get the result of the operation
    int perform(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }
    vector<int> diffWaysToCompute(string exp) {
        
        vector<int> results;
        for(int i=0;i<exp.size();i++)
        {
            if(exp[i] == '+' || exp[i] =='-' || exp[i]=='*')
            {
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                
                // list of second operands
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));
                 for(int x : left) {
                    for(int y : right) {
                        int val = perform(x, y, exp[i]);
                        results.push_back(val);
                    }
                }
            }
        }

        if(results.empty()){
            results.push_back(stoi(exp));
        }
        return results;
    }
};