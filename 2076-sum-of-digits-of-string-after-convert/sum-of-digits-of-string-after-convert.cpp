class Solution {
public:
    int getLucky(string s, int k) {
           string transformed = "";
        for (char c : s) {
            int val = (c - 'a') + 1; // Convert character to its position (1 to 26)
            transformed += to_string(val); // Append the value as a string to the transformed string
        }

        // Perform the sum operation k times
        int sum = 0;
        while (k-- > 0) {
            sum = 0;
            for (char c : transformed) {
                sum += c - '0'; // Convert char digit to integer and sum them
            }
            transformed = to_string(sum); // Update transformed to be the new sum as a string
        }

        return sum; // Return the final sum after k transformations
    
    }
};