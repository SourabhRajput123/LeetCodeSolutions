class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
                int n = nums.size();
        int minLength = INT_MAX;
        
        // Iterate through all possible subarrays
        for (int i = 0; i < n; ++i) {
            int bitwiseOR = 0;
            // Iterate through subarrays starting from index i
            for (int j = i; j < n; ++j) {
                // Update the bitwise OR value
                bitwiseOR |= nums[j];
                // Check if the current subarray is special
                if (bitwiseOR >= k) {
                    // Update the minimum length
                    minLength = std::min(minLength, j - i + 1);
                    break;  // No need to check further subarrays starting from index i
                }
            }
        }
        
        // If minLength remains INT_MAX, no special subarray found
        return (minLength == INT_MAX) ? -1 : minLength;
    }
};