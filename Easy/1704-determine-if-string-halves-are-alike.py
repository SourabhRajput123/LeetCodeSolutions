class Solution(object):
    def count_vowels(self, s):
        vowels = set("aeiouAEIOU")
        count = 0
        for char in s:
            if char in vowels:
                count += 1
        return count
    
    def halvesAreAlike(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        half = n // 2
        first_half = s[:half]
        second_half = s[half:]
        
        return self.count_vowels(first_half) == self.count_vowels(second_half)
