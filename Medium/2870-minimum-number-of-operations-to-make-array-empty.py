from collections import Counter

class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Count the frequency of each element
        freq_map = Counter(nums)
        
        # Initialize variables to track the number of operations
        operations = 0
        pairs = []
        
        # Iterate through the frequencies
        for freq in freq_map.values():
            # If there are groups of 3, remove them directly
            if freq % 3 == 0:
                operations += freq // 3
            # If there are groups of 2, keep track of them
            elif freq % 3 == 1:
                pairs.append(1)
            # If there are groups of 1, check if there are pairs available to eliminate them
            else:
                if pairs:
                    pairs.pop()
                else:
                    return -1
        
        # If there are remaining pairs, use them to eliminate single elements
        if pairs:
            operations += len(pairs)
        else:
            return -1
        
        return operations
