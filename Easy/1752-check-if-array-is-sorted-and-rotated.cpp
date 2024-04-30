class Solution {
public:
    bool check(vector<int>& nums) {
                int n = nums.size();
        int pivot = -1;

        // Find the pivot element
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot found, the array is already sorted
        if (pivot == -1) {
            return true;
        }

        // Check if elements before and after the pivot are in non-decreasing order
        for (int i = pivot + 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                return false; // Elements after pivot are not in non-decreasing order
            }
        }

        return nums[n - 1] <= nums[0]; // Check if elements before pivot are in non-decreasing order
    }
};