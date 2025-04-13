class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.empty())return "";

    // step 1 : transform string
        string t = "#";
        for(char c: s)
        {
            t+=c;
            t+="#";
        }

        int n = t.size();
        vector<int>P(n,0);

        int center = 0,right =0;
        int maxlen =0 ,centreIndx =0;

       
    for (int i = 0; i < n; ++i) {
        int mirror = 2 * center - i;

        if (i < right)
            P[i] = min(right - i, P[mirror]);

        // Try to expand around center i
        int a = i + P[i] + 1;
        int b = i - P[i] - 1;
        while (a < n && b >= 0 && t[a] == t[b]) {
            P[i]++;
            a++;
            b--;
        }

        // Update center and right boundary
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }

        // Track max length and its center
        if (P[i] > maxlen) {
            maxlen = P[i];
            centreIndx = i;
        }
    }
      // Step 3: Extract original substring
    int start = (centreIndx - maxlen) / 2;
    return s.substr(start, maxlen);
    }
};