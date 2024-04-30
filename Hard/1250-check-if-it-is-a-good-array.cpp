class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
                // Function to calculate the greatest common divisor (gcd)
        auto gcd = [](int a, int b) {
            while (b) {
                a %= b;
                swap(a, b);
            }
            return a;
        };
        
        int g = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            g = gcd(g, nums[i]);
        }
        
        return g == 1;
    }
};