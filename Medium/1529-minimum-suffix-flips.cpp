class Solution {
public:
    int minFlips(string target) {
                int flips = 0;
        string s(target.length(), '0'); // Initialize s with all zeros
        for (int i = 0; i < target.length(); ++i) {
            if (s[i] != target[i]) {
                flips++;
                for (int j = i; j < target.length(); ++j) {
                    s[j] = (s[j] == '0') ? '1' : '0'; // Toggle the bits
                }
            }
        }
        return flips;
    }
};