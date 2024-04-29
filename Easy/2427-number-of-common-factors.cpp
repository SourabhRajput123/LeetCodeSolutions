class Solution {
public:
    int commonFactors(int a, int b) {
    // Initialize the count of common factors to 0
    int count = 0;
    
    // Iterate through all numbers from 1 to the minimum of a and b
    for (int i = 1; i <= min(a, b); ++i) {
        // If both a and b are divisible by i, increment the count
        if (a % i == 0 && b % i == 0) {
            ++count;
        }
    }
    
    // Return the count of common factors
    return count;
}

};