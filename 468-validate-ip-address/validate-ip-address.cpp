class Solution {
public:
    string validIPAddress(string queryIP) {
        // Check for IPv4
        if (queryIP.find('.') != string::npos) {
            stringstream ss(queryIP);
            string word;
            vector<string> words;

            while (getline(ss, word, '.')) {
                if (word.empty() || word.size() > 3) return "Neither";
                if (word[0] == '0' && word.size() > 1) return "Neither";
                for (char c : word) {
                    if (!isdigit(c)) return "Neither";
                }
                int val = stoi(word);
                if (val < 0 || val > 255) return "Neither";
                words.push_back(word);
            }

            if (words.size() == 4 && queryIP[queryIP.size()-1] != '.') return "IPv4";
            return "Neither";
        }

        // Check for IPv6
        else if (queryIP.find(':') != string::npos) {
            stringstream ss(queryIP);
            string word;
            vector<string> words;

            while (getline(ss, word, ':')) {
                if (word.empty() || word.size() > 4) return "Neither";
                for (char c : word) {
                    if (!isxdigit(c)) return "Neither";
                }
                words.push_back(word);
            }

            if (words.size() == 8 &&(queryIP[queryIP.size()-1] !=':') ) return "IPv6";
            return "Neither";
        }

        return "Neither";
    }
};
