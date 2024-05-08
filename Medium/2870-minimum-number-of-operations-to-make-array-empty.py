from collections import Counter

class Solution(object):
    def minOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Count the frequency of each element
        freq_map = Counter(nums)
        
        # Initialize variables to track the number of pairs and triples
        pairs = 0
        triples = 0
        
        # Iterate through the frequencies
        for freq in freq_map.values():
            # Count how many pairs and triples can be formed for each frequency
            pairs += freq // 2
            triples += freq // 3
        
        # Check if the total count of pairs and triples is sufficient to empty the array
        if pairs >= triples:
            # Calculate the total number of operations required
            return pairs * 2 + triples * 3
        else:
            return -1
