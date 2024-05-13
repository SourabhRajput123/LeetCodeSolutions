class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # Helper function to reverse a linked list
        def reverseList(node):
            prev = None
            curr = node
            while curr:
                next_node = curr.next
                curr.next = prev
                prev = curr
                curr = next_node
            return prev
        
        # Helper function to get the middle of the linked list
        def getMiddle(node):
            slow = node
            fast = node
            while fast and fast.next:
                slow = slow.next
                fast = fast.next.next
            return slow
        
        # Helper function to compare two linked lists
        def compareLists(l1, l2):
            while l1 and l2:
                if l1.val != l2.val:
                    return False
                l1 = l1.next
                l2 = l2.next
            return True
        
        if not head or not head.next:
            return True
        
        # Find the middle of the linked list
        middle = getMiddle(head)
        
        # Reverse the second half of the linked list
        second_half = reverseList(middle)
        
        # Compare the first and second halves of the linked list
        return compareLists(head, second_half)
