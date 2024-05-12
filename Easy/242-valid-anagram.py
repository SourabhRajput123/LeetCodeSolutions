class Solution(object):
    def isAnagram(self, s, t):
        if len(s) != len(t):
            return False
        
        # Create dictionaries to count character occurrences
        count_s = {}
        count_t = {}

        # Count occurrences in string s
        for char in s:
            count_s[char] = count_s.get(char, 0) + 1

        # Count occurrences in string t
        for char in t:
            count_t[char] = count_t.get(char, 0) + 1

        # Compare the counts
        return count_s == count_t
