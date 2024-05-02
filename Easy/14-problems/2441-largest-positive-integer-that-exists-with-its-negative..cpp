class Solution {
public:
    int findMaxK(vector<int>& nums) {
                int max_k = -1; // Initialize max_k to -1
        std::unordered_set<int> nums_set(nums.begin(), nums.end()); // Convert nums to a set for faster lookup
        
        for (int num : nums) {
            if (nums_set.count(-num)) { // Check if the negative counterpart exists
                max_k = std::max(max_k, std::abs(num)); // Update max_k if necessary
            }
        }
        
        return max_k != -1 ? max_k : -1; // Return -1 if no valid k is found
    }
};