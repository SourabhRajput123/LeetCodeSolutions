class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort()  # Sort the greed factors
        s.sort()  # Sort the cookie sizes
        
        i = j = 0  # Pointers for greed factors and cookie sizes
        
        count = 0  # Count of content children
        
        while i < len(g) and j < len(s):
            if s[j] >= g[i]:  # If the cookie size is sufficient for the child's greed factor
                count += 1
                i += 1  # Move to the next child
            j += 1  # Move to the next cookie
            
        return count
