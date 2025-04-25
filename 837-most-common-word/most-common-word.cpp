
class Solution {
public:
     // Helper function to convert a string to lowercase
    string to_lower(string str) {
        for (char &c : str) {
            c = tolower(c);
        }
        return str;
    }

    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> umap;
        unordered_set<string> bannedSet(banned.begin(), banned.end()); // Set for quick lookup
        string tmp = "";
        
        // Process the paragraph character by character
        for (int i = 0; i < paragraph.size(); i++) {
            // Check if the character is a space or a non-alphabetical character (punctuation)
            if (isspace(paragraph[i]) || ispunct(paragraph[i])) {
                if (!tmp.empty()) {
                    // Convert the word to lowercase and reset tmp for the next word
                    string word = to_lower(tmp);
                    tmp = "";  // Reset the tmp string
                    
                    // If the word is not banned, increment its count in the map
                    if (bannedSet.find(word) == bannedSet.end()) {
                        umap[word]++;
                    }
                }
            } else {
                tmp += paragraph[i]; // Build the word
            }
        }

        // To handle the last word after the loop ends
        if (!tmp.empty()) {
            string word = to_lower(tmp);
            if (bannedSet.find(word) == bannedSet.end()) {
                umap[word]++;
            }
        }

        // Find the most common word
        string ans = "";
        int maxFreq = 0;
        for (auto& u : umap) {
            if (u.second > maxFreq) {
                ans = u.first;
                maxFreq = u.second;
            }
        }

        return ans;
    }
};


