class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        """
        :type tickets: List[int]
        :type k: int
        :rtype: int
        """
        # Initialize variables
        time = 0
        queue = [i for i in range(len(tickets))]
        remain_tickets = tickets[:]
        
        # Simulate the process of people buying tickets
        while queue:
            # Increment time by 1 for each iteration
            time += 1
            # Check if the person at the front of the queue finishes buying tickets
            if remain_tickets[queue[0]] == 0:
                queue.pop(0)  # Remove the person from the queue
                continue
            # Decrement the remaining tickets for the person at the front of the queue
            remain_tickets[queue[0]] -= 1
            # Move the person to the end of the queue
            queue.append(queue.pop(0))
            # If the person at position k finishes buying tickets, return the time
            if queue[0] == k and remain_tickets[queue[0]] == 0:
                return time
        return time
