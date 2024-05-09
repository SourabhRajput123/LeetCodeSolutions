class Solution(object):
    def maximumHappinessSum(self, happiness, k):
        """
        :type happiness: List[int]
        :type k: int
        :rtype: int
        """
        # Sort the happiness array in non-decreasing order
        happiness.sort(reverse=True)
        
        # Initialize the maximum sum
        max_sum = 0
        
        # Iterate through the first k elements
        for i in range(k):
            # If the current happiness value is negative after decrementing, break the loop
            if happiness[i] - i <= 0:
                break
            # Add the happiness value after decrementing to the maximum sum
            max_sum += happiness[i] - i
        
        return max_sum
