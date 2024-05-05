class Solution {
public:
    int minFlips(string target) {
                int flips = 0;
        char state = '0'; // Initialize the current state to '0'
        for (char c : target) {
            if (c != state) {
                flips++; // Increment flips when the current character is different from the state
                state = c; // Update the state
            }
        }
        return flips;
    }
};