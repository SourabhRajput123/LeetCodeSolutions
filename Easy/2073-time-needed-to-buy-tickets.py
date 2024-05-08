class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        """
        :type tickets: List[int]
        :type k: int
        :rtype: int
        """
        # Initialize variables
        time = 0
        n = len(tickets)
        
        # Simulate the process of people buying tickets
        while tickets[k] > 0:
            # Increment time by the number of people in line
            time += 1
            for i in range(n):
                # If person has tickets left, decrement and check if it's person k
                if tickets[i] > 0:
                    tickets[i] -= 1
                    if i == k and tickets[i] == 0:
                        return time
        return time
