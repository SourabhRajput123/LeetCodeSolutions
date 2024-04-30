class Solution {
public:
    bool checkString(string s) {
                bool foundB = false;

        for (char c : s) {
            if (c == 'b') {
                foundB = true;
            } else if (c == 'a' && foundB) {
                return false; // 'a' appears after 'b'
            }
        }

        return true; // No 'a' appears after 'b'
    }
};