class Solution {
public:
    int getNextIndex(vector<int>& nums, int currentIndex) {
        int n = nums.size();
        return (currentIndex + nums[currentIndex] + n) % n;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue; // Skip zero values
            int slow = i, fast = i;
            bool isForward = nums[i] > 0; // Direction of movement
            
            do {
                slow = getNextIndex(nums, slow); // Move slow pointer one step forward
                fast = getNextIndex(nums, getNextIndex(nums, fast)); // Move fast pointer two steps forward
                
                // Check if direction changes
                if ((nums[slow] > 0) != isForward || (nums[fast] > 0) != isForward) {
                    break;
                }
                
                // If both pointers meet, we found a cycle
                if (slow == fast) {
                    // Check if the cycle has more than one element
                    if (slow == getNextIndex(nums, slow)) break;
                    return true;
                }
            } while (true);
            
            // Mark all elements of the cycle as visited
            slow = i;
            int val = nums[i];
            while (nums[slow] != 0 && nums[slow] > 0 == isForward) {
                int next = getNextIndex(nums, slow);
                nums[slow] = 0; // Mark as visited
                slow = next;
            }
        }
        
        return false;
    }
};
