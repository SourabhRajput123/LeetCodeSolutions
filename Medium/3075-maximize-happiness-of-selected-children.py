class Solution(object):
    def maximumHappinessSum(self, happiness, k):
        """
        :type happiness: List[int]
        :type k: int
        :rtype: int
        """
        # Sort the happiness array in non-decreasing order
        happiness.sort()
        
        # Select the first k elements from the sorted array
        max_sum = sum(happiness[-k:])
        
        return max_sum
