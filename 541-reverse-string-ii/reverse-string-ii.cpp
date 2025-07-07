class Solution {
public:
    void reverse(string &s, int i, int j){
        while( i < j ) {
            swap(s[i],s[j]);
            j--;
            i++;
        }
    }
    string reverseStr(string s, int k) {
        int n = s.length();
        for(int i = 0 ; i < n ; i += 2*k ){
            int r = min(i+k-1, n-1);
            reverse(s, i, r);
        }
        return s;
    }
};
