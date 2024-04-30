class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
                // Create a dictionary to store the indices of elements
        unordered_map<int, int> num_indices;
        
        // Iterate through the array
        for (int i = 0; i < nums.size(); ++i) {
            // Calculate the complement needed to reach the target
            int complement = target - nums[i];
            
            // Check if the complement exists in the dictionary
            if (num_indices.find(complement) != num_indices.end()) {
                // If found, return the indices of the current element and its complement
                return {num_indices[complement], i};
            }
            
            // If the complement doesn't exist, store the index of the current element
            num_indices[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector
        return {};
    }
};