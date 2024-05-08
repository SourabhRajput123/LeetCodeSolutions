class Solution(object):
    def timeRequiredToBuy(self, tickets, k):
        """
        :type tickets: List[int]
        :type k: int
        :rtype: int
        """
        # Initialize the queue with the number of tickets each person wants to buy
        queue = [(tickets[i], i) for i in range(len(tickets))]
        time = 0
        
        # Simulate the process of people buying tickets until the person at position k finishes buying tickets
        while queue:
            # Buy tickets for the person at the front of the queue
            num_tickets, person_index = queue.pop(0)
            # Update the time taken
            time += min(num_tickets, 1) * len(tickets)
            # Update the number of tickets the person wants to buy
            num_tickets -= min(num_tickets, 1)
            # If the person still wants to buy more tickets, put them back in the queue
            if num_tickets > 0:
                queue.append((num_tickets, person_index))
            # If the person at position k finishes buying tickets, return the time taken
            if person_index == k and num_tickets == 0:
                return time
        return time  # This line is not strictly necessary, but included for clarity
