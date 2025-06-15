class Solution {
public:
    int maxDiff(int num) {
        string strMax = to_string(num);
        string strMin = strMax;

        // Step 1: Create max number by replacing the first digit that is not 9 with 9
        char toReplaceMax = '\0';
        for (char c : strMax) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }

        if (toReplaceMax != '\0') {
            for (char& c : strMax) {
                if (c == toReplaceMax) c = '9';
            }
        }

        // Step 2: Create min number by replacing a suitable digit with 1 or 0
        char toReplaceMin = '\0';
        char replaceWith = '\0';

        if (strMin[0] != '1') {
            // First digit not 1, replace it with 1
            toReplaceMin = strMin[0];
            replaceWith = '1';
        } else {
            // Find a digit other than first that is not 0 and not equal to first
            for (int i = 1; i < strMin.size(); i++) {
                if (strMin[i] != '0' && strMin[i] != strMin[0]) {
                    toReplaceMin = strMin[i];
                    replaceWith = '0';
                    break;
                }
            }
        }

        if (toReplaceMin != '\0') {
            for (char& c : strMin) {
                if (c == toReplaceMin) c = replaceWith;
            }
        }

        return stoi(strMax) - stoi(strMin);
    }
};
