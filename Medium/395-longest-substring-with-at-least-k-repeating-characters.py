class Solution(object):
    def longestSubstring(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if not s:
            return 0
        
        # Count the frequency of each character
        char_count = {}
        for char in s:
            char_count[char] = char_count.get(char, 0) + 1
        
        # Find the character(s) that occur less than k times
        invalid_chars = set(char for char, count in char_count.items() if count < k)
        
        if not invalid_chars:
            return len(s)
        
        # Split the string by invalid characters and recursively check each substring
        max_length = 0
        start = 0
        for i, char in enumerate(s):
            if char in invalid_chars:
                max_length = max(max_length, self.longestSubstring(s[start:i], k))
                start = i + 1
        
        # Check the last substring
        max_length = max(max_length, self.longestSubstring(s[start:], k))
        
        return max_length
