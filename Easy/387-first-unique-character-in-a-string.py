class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        # Create a dictionary to store the frequency of each character
        freq = {}
        
        # Count the frequency of each character in the string
        for char in s:
            freq[char] = freq.get(char, 0) + 1
        
        # Iterate through the string again to find the first character with frequency 1
        for i, char in enumerate(s):
            if freq[char] == 1:
                return i
        
        # If no non-repeating character is found, return -1
        return -1
