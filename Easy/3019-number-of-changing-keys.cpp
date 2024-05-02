class Solution {
public:
    int countKeyChanges(string s) {
                int changes = 0;
        char lastChar = '\0'; // Initialize last character as null
        
        for (char& c : s) {
            c = tolower(c); // Convert character to lowercase
            if (c != lastChar) { // Check if character is different from last character
                changes++; // Increment changes count
                lastChar = c; // Update last character
            }
        }
        
        return changes-1;
    }
};