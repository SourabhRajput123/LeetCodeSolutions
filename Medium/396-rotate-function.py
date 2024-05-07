class Solution(object):
    def maxRotateFunction(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        
        # Calculate F(0)
        F = sum(i * num for i, num in enumerate(nums))
        
        # Calculate the sum of all elements in the array
        total_sum = sum(nums)
        
        # Initialize the max rotation function value
        max_F = F
        
        # Calculate F(k) for k = 1 to n-1
        for k in range(1, n):
            # Calculate F(k) from F(k-1)
            F += total_sum - n * nums[n - k]
            # Update max_F if necessary
            max_F = max(max_F, F)
        
        return max_F
