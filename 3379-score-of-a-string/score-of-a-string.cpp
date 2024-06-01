class Solution {
public:
    int scoreOfString(string s) {
        int diff=0;
     for(int i=1;i<s.size();i++)
     {
        /*
        int sum1=int(s[i])+int(s[i+1]);
        int sum2=int(s[i+1])+int(s[i+2]);
        diff +=abs(sum1-sum2);*/
        diff +=abs(s[i]-s[i-1]);

     }
     return diff;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();