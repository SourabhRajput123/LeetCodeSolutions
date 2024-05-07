class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []
        num = 0
        curr_str = ''
        
        for char in s:
            if char.isdigit():
                num = num * 10 + int(char)
            elif char == '[':
                stack.append((curr_str, num))
                curr_str, num = '', 0
            elif char == ']':
                prev_str, repeat = stack.pop()
                curr_str = prev_str + repeat * curr_str
            else:
                curr_str += char
                
        return curr_str
