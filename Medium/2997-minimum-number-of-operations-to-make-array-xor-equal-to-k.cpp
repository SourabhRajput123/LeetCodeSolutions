class Solution {
public:
int minOperations(vector<int>& nums, int k) {
    int xorResult = 0;
    for (int num : nums) {
        xorResult ^= num;
    }

    // Count the number of differing bits between xorResult and k
    int diffBits = __builtin_popcount(xorResult ^ k);

    // The minimum number of operations required is equal to the number of differing bits
    return diffBits;
}

};