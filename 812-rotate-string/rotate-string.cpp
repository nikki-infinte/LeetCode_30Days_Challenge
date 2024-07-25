class Solution {
public:
  
  bool rotateString(std::string s, std::string goal) {
    if (s.length() != goal.length()) {
        return false;
    }

    string ss=s+s;
   return ss.find(goal) != std::string::npos;

}
};