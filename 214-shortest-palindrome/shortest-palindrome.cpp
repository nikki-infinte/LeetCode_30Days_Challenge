class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        
        int i = 0; //  i = 0 to n-1
        int j = n - 1; // j = n-1 to 0
        while (j >= 0) {
            if (s[i] == s[j]) {
                i++;
            }
            j--;
        }
   
        string remain = s.substr(i); // s trim from i to end
        if( remain.size()==0 ){ return s; }

        string rev_remain = remain;
        reverse(rev_remain.begin(), rev_remain.end());
        
        // Uncomment Below to see How LPP is printing for each step
        // cout<< rev_remain <<" "<< s.substr(0,i) <<" "<< remain <<endl;
        
        // recurively calculate shortest palindrome in the longest prefix string
        return rev_remain + shortestPalindrome(s.substr(0, i)) + remain;
    }
};