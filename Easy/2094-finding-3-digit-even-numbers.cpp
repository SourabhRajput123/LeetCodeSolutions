class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        
        // Generate all possible three-digit numbers between 100 and 999
        for (int i = 1; i <= 9; ++i) {
            for (int j = 0; j <= 9; ++j) {
                for (int k = 0; k <= 9; ++k) {
                    int num = i * 100 + j * 10 + k;
                    if (num % 2 == 0 && num >= 100 && num <= 999) {
                        // Check if the number can be formed using the digits
                        if (canFormNumber(num, digits)) {
                            result.push_back(num);
                        }
                    }
                }
            }
        }
        
        return result;
    }
    
    bool canFormNumber(int num, vector<int>& digits) {
        vector<int> count(10, 0); // Count of digits in digits array
        while (num > 0) {
            int digit = num % 10;
            count[digit]++;
            num /= 10;
        }
        for (int digit : digits) {
            if (count[digit] == 0) {
                return false; // Number cannot be formed
            }
            count[digit]--; // Reduce count of used digit
        }
        return true;
    }
};