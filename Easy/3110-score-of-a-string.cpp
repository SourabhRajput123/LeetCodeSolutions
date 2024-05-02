class Solution {
public:
    int scoreOfString(string s) {
              int score = 0;
        
        // Iterate through the characters of the string
        for (int i = 1; i < s.length(); ++i) {
            // Calculate the absolute difference between the ASCII values of adjacent characters
            score += abs(s[i] - s[i - 1]);
        }
        
        return score;  
    }
};