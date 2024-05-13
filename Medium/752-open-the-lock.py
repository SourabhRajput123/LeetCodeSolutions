from collections import deque

class Solution(object):
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        # Convert deadends to a set for faster lookup
        deadends_set = set(deadends)
        
        # Check if the target is in the deadends, return -1 if it is
        if target in deadends_set or "0000" in deadends_set:
            return -1
        
        # Initialize the queue with the initial state and the number of moves
        queue = deque([("0000", 0)])
        
        # Perform BFS
        while queue:
            # Dequeue the current state and the number of moves
            current_state, moves = queue.popleft()
            
            # Check if the current state is the target state
            if current_state == target:
                return moves
            
            # Generate all possible next states
            for i in range(4):
                for j in [-1, 1]:
                    next_state = current_state[:i] + str((int(current_state[i]) + j) % 10) + current_state[i+1:]
                    
                    # Check if the next state is not in the deadends
                    if next_state not in deadends_set:
                        # Add the next state to the queue for further exploration
                        queue.append((next_state, moves + 1))
                        # Add the next state to the deadends to avoid revisiting it
                        deadends_set.add(next_state)
        
        # If the target state is not found, return -1
        return -1
