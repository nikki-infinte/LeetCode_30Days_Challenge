class Solution {
public:
  
  bool rotateString(std::string s, std::string goal) {
    if (s.length() != goal.length()) {
        return false;
    }

    std::string rotated = s;

    for (int i = 0; i < s.length(); ++i) {
        // Rotate the string by one position to the left
        rotated = rotated.substr(1) + rotated[0];

        // Check if the rotated string matches the goal
        if (rotated == goal) {
            return true;
        }
    }

    return false;
}
};