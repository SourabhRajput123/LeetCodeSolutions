class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> result; // Vector to store elements not equal to val
        
        // Copy elements not equal to val to the result vector
        for (int num : nums) {
            if (num != val) {
                result.push_back(num);
            }
        }
        
        // Update the original nums array with the elements from the result vector
        nums = result;
        
        return result.size(); // Return the number of elements not equal to val
    }
};
