class Solution {
public:
    int getNextIndex(vector<int>& nums, int currentIndex) {
        int n = nums.size();
        int nextIndex = currentIndex + nums[currentIndex];
        if (nextIndex < 0) {
            return n + (nextIndex % n); // Adjust for negative values
        } else {
            return nextIndex % n;
        }
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
                
                // Check if direction changes or signs change
                if ((nums[slow] > 0) != isForward || (nums[fast] > 0) != isForward || nums[fast] * nums[slow] < 0) {
                    break;
                }
                
                // If both pointers meet, we found a cycle
                if (slow == fast) {
                    // Check if the cycle has more than one element
                    if (slow == getNextIndex(nums, slow)) break;
                    
                    // Validate the cycle: check if all elements have the same sign
                    int temp = slow;
                    do {
                        temp = getNextIndex(nums, temp);
                    } while (temp != slow && nums[temp] * nums[slow] > 0);
                    
                    // If all elements in the cycle have the same sign, return true
                    if (temp == slow) return true;
                    
                    break;
                }
            } while (true);
            
            // Mark all elements of the cycle as visited
            slow = i;
            int val = nums[i];
            while (nums[slow] != 0 && nums[slow] * val > 0) {
                int next = getNextIndex(nums, slow);
                nums[slow] = 0; // Mark as visited
                slow = next;
            }
        }
        
        return false;
    }
};
