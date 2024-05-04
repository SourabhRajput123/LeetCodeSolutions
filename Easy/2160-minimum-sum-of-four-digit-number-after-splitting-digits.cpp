class Solution {
public:
    int minimumSum(int num) {
               // Extract digits from the given number
        int thousands = num / 1000;
        int hundreds = (num / 100) % 10;
        int tens = (num / 10) % 10;
        int ones = num % 10;
        
        // Store the digits in a vector
        std::vector<int> digits = {thousands, hundreds, tens, ones};
        
        // Sort the digits in ascending order
        std::sort(digits.begin(), digits.end());
        
        // Initialize the minimum sum
        int minSum = INT_MAX;
        
        do {
            // Form new1 and new2 using the sorted digits
            int new1 = digits[0] * 10 + digits[1]; // Two smallest digits
            int new2 = digits[2] * 10 + digits[3]; // Two largest digits
            
            // Calculate the sum of new1 and new2
            int sum = new1 + new2;
            
            // Update the minimum sum if needed
            minSum = std::min(minSum, sum);
        } while (std::next_permutation(digits.begin(), digits.end()));
        
        return minSum;
    }
};