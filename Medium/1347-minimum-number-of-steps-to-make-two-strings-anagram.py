class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        counter = {}
        for char in s:
            counter[char] = counter.get(char, 0) + 1
        
        steps = 0
        for char in t:
            if char in counter and counter[char] > 0:
                counter[char] -= 1
            else:
                steps += 1
        
        return steps
