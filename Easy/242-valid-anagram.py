class Solution(object):
    def isAnagram(self, s, t):
        # Check if the sorted versions of the strings are equal
        return sorted(s) == sorted(t)
