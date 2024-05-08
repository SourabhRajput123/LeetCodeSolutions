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
        
        # Use any remaining pairs to create triples wherever possible
        triples += pairs // 3
        
        # Check if the total count of triples is sufficient to empty the array
        if triples * 3 <= sum(freq_map.values()):
            # Calculate the total number of operations required
            return pairs * 2 + triples * 3
        else:
            return -1
