class Solution {
public:
    int romanToInt(string s) {
        

           unordered_map<char, int> roman_value = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int num=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(roman_value[s[i]] < roman_value[s[i+1]])
            {
                num-=roman_value[s[i]];
            }else{
                num+=roman_value[s[i]];
            }
        }
          num += roman_value[s.back()];
        return num;
    }
};