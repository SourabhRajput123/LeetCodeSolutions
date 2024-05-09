class Solution(object):
    def maxScore(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_score = 0
        
        # Iterate through each possible split position
        for i in range(1, len(s)):
            # Count the number of zeros on the left side
            zeros_left = s[:i].count('0')
            # Count the number of ones on the right side
            ones_right = s[i:].count('1')
            # Update the maximum score with the maximum value found so far
            max_score = max(max_score, zeros_left + ones_right)
        
        return max_score
