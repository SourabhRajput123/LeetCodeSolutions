class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        def check_next(index):
            count = 0
            while index < len(data):
                if data[index] >> 7 == 0:
                    return index, count
                elif data[index] >> 5 == 0b110:
                    count = 1
                    break
                elif data[index] >> 4 == 0b1110:
                    count = 2
                    break
                elif data[index] >> 3 == 0b11110:
                    count = 3
                    break
                else:
                    return -1, -1
                index += 1
            if index + count >= len(data):
                return -1, -1
            for i in range(index + 1, index + count + 1):
                if data[i] >> 6 != 0b10:
                    return -1, -1
            return index + count, count
        
        index = 0
        while index < len(data):
            index, count = check_next(index)
            if index == -1:
                return False
            index += 1
        return True
