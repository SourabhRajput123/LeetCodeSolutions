class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long count = 0;
        int mask = 0; // Bitmask to represent the frequency of characters
        unordered_map<int, int> freqCount; // Map to store frequency count of each bitmask
        freqCount[0] = 1; // Initialize with an empty string

        for (char c : word) {
            int bit = 1 << (c - 'a'); // Set the corresponding bit for the character
            mask ^= bit; // Toggle the bit for the character
            count += freqCount[mask]; // Add the count of wonderful substrings with current bitmask
            for (int i = 0; i < 10; ++i) {
                count += freqCount[mask ^ (1 << i)]; // Add the count of wonderful substrings with one character flipped
            }
            freqCount[mask]++; // Increment the count of substrings with current bitmask
        }

        return count;

    }
};