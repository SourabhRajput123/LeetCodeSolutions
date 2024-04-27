class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int count = 0;
        int oddCount = 0;
        int result = 0;
        
        while (right < n) {
            if (nums[right] % 2 == 1) {
                oddCount++;
            }
            
            if (oddCount == k) {
                count = 1;
                while (right + 1 < n && nums[right + 1] % 2 == 0) {
                    right++;
                    count++;
                }
                
                int leftCount = 0;
                while (nums[left] % 2 == 0) {
                    left++;
                    leftCount++;
                }
                
                result += (leftCount + 1) * count;
                left++;
                oddCount--;
            }
            
            right++;
        }
        
        return result;
    }
};