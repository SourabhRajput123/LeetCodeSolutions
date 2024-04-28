class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left = 0; // Pointer for iterating through the array
        int right = 0; // Pointer for placing non-zero elements
        
        // Iterate through the array
        while (left < n) {
            // If the current element is non-zero, swap it with the element at the right pointer's position
            if (nums[left] != 0) {
                swap(nums[left], nums[right]);
                right++; // Move the right pointer to the next position
            }
            left++; // Move the left pointer to the next position
        }
    }
};
