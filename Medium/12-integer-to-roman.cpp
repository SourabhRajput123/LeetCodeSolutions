class Solution {
public:
    string intToRoman(int num) {
                // Arrays to store symbols and their corresponding values
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string result;
        
        // Iterate through the values
        for (int i = 0; i < values.size(); ++i) {
            // Repeat the symbol until the value is subtracted completely
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        
        return result;
    }
};