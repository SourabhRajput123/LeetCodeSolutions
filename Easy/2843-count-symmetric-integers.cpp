class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int num = low; num <= high; ++num) {
            if (isSymmetric(num))
                ++count;
        }
        return count;
    }
    
private:
    bool isSymmetric(int num) {
        string numStr = to_string(num);
        int n = numStr.size();
        for (int i = 0; i < n / 2; ++i) {
            if (numStr[i] != numStr[n - 1 - i])
                return false;
        }
        return true;
    }
};
0