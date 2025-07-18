class Solution {
public:
    
    
    bool isValid(string word) {
         if (word.length() < 3) {
            return false;
        }

        bool hasVowel = false;
        bool hasConsonant = false;

        // Iterate through each character in the word
        for (char ch : word) {
            // Check if the character is alphanumeric
            if (!isalnum(ch)) {
                return false;
            }

            // Check if the character is a vowel
            if (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' || tolower(ch) == 'o' || tolower(ch) == 'u') {
                hasVowel = true;
            }
            // Check if the character is a consonant
            else if (isalpha(ch)) {
                hasConsonant = true;
            }
        }

        // Return true if both a vowel and a consonant are found
        return hasVowel && hasConsonant;
    
    }
};