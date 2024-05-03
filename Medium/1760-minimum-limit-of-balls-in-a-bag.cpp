class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
                int left = 1, right = *max_element(nums.begin(), nums.end());
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (possible(nums, maxOperations, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        return left;
    }
    
private:
    bool possible(vector<int>& nums, int maxOperations, int penalty) {
        int count = 0;
        for (int num : nums) {
            count += (num - 1) / penalty;
        }
        return count <= maxOperations;
    }
};