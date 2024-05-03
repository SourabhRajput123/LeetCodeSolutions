class Solution {
public:
    string replaceDigits(string s) {
                for (int i = 1; i < s.length(); i += 2) { // Iterate through odd indices
            s[i] = shift(s[i - 1], s[i] - '0'); // Replace digit with shifted character
        }
        return s;
    }
    
private:
    char shift(char c, int x) {
        return c + x; // Shift character forward by x positions
    }
};