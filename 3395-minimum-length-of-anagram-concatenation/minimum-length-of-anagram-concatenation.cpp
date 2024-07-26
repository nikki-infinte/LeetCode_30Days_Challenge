class Solution {
public:
  bool check(const std::string &s, int n) {
        std::unordered_map<char, int> baseFreq;
        for (int i = 0; i < n; i++) {
            baseFreq[s[i]]++;
        }
        for (int i = n; i < s.size(); i += n) {
            std::unordered_map<char, int> currentFreq;
            for (int j = i; j < i + n; j++) {
                currentFreq[s[j]]++;
            }
            if (currentFreq != baseFreq) {
                return false;
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
     

        int size = s.size();
        for (int i = 1; i <= size; i++) {
            if (size % i == 0 && check(s, i)) {
                return i;
            }
        }
        return size;
    }
       
    
};