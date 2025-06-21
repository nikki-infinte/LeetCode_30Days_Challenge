class Solution {
public:

   unordered_map<string, bool> memo;

bool dfs(string& s, int index, int open) {
    if (open < 0) return false;
    if (index == s.size()) return open == 0;

    string key = to_string(index) + "," + to_string(open);
    if (memo.count(key)) return memo[key];

    bool res = false;
    if (s[index] == '(')
        res = dfs(s, index + 1, open + 1);
    else if (s[index] == ')')
        res = dfs(s, index + 1, open - 1);
    else // '*'
        res = dfs(s, index + 1, open + 1) || 
              dfs(s, index + 1, open - 1) || 
              dfs(s, index + 1, open);

    return memo[key] = res;
}

    bool checkValidString(string s) {

      return  dfs(s,0,0);
    }
};