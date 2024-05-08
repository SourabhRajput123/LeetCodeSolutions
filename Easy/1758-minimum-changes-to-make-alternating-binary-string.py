class Solution(object):
    def minOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        # Initialize counters for changes to '0' and '1'
        change_to_zero = 0
        change_to_one = 0
        
        # Iterate through the string
        for i in range(n):
            # Check if the character should be '0' or '1' based on the index
            expected_char = '0' if i % 2 == 0 else '1'
            # Increment the counter for the opposite character if needed
            if s[i] != expected_char:
                if s[i] == '0':
                    change_to_one += 1
                else:
                    change_to_zero += 1
        
        # Return the minimum number of changes needed
        return min(change_to_zero, change_to_one)
