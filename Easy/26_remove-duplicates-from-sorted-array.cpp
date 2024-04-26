class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0; // If the array is empty, there are no duplicates
        
        int insertPos = 0; // Position to insert the next unique element
        
        for (int i = 1; i < nums.size(); ++i) {
            // If the current element is different from the previous element
            if (nums[i] != nums[insertPos]) {
                // Move the current element to the next insertion position
                nums[++insertPos] = nums[i];
            }
        }
        
        return insertPos + 1; // Number of unique elements
    }
};