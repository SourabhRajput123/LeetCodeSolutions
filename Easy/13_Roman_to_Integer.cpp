class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        int prevValue = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            int currentValue = romanValues[s[i]];
            
            // If the current value is greater than the previous value, we subtract the previous value
            if (currentValue > prevValue) {
                result += currentValue - 2 * prevValue;
            } else {
                result += currentValue;
            }
            
            prevValue = currentValue;
        }
        
        return result;
    }
};