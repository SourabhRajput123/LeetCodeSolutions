class Solution {
public:
    int nextGreaterElement(int n) {
               // Convert integer to string for easier manipulation
        std::string s = std::to_string(n);
        
        // Find the first index where a smaller digit precedes a larger one
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        
        // If no such index is found, n is the largest possible integer with the same digits
        if (i == -1) {
            return -1;
        }
        
        // Find the smallest digit greater than s[i] to the right of i
        int j = s.size() - 1;
        while (j > i && s[j] <= s[i]) {
            j--;
        }
        
        // Swap digits at positions i and j
        std::swap(s[i], s[j]);
        
        // Sort the digits to the right of position i
        std::sort(s.begin() + i + 1, s.end());
        
        // Convert string back to integer
        long long res = std::stoll(s);
        
        // Check if the result exceeds 32-bit integer limit
        return (res > INT_MAX) ? -1 : res; 
    }
};