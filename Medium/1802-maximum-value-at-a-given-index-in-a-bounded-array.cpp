class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
                long long left = 1, right = maxSum;
        
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            
            if (isValid(n, index, maxSum, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        
        return left;
    }
    
private:
    bool isValid(int n, int index, int maxSum, long long target) {
        long long sum = 0;
        
        // Calculate the sum of the elements on the left side of index
        long long leftSum = (index + 1) * target - ((index + 1) * index) / 2;
        if (leftSum <= 0) return false;
        sum += leftSum;
        
        // Calculate the sum of the elements on the right side of index
        long long rightSum = (n - index) * target - ((n - index - 1) * (n - index)) / 2;
        if (rightSum <= 0) return false;
        sum += rightSum;
        
        // Check if the total sum does not exceed maxSum
        return sum - target <= maxSum;
    }
};