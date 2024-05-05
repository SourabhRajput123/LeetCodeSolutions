class Solution {
public:
    // Iterative solution
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    // Recursive solution
    ListNode* reverseListRecursive(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* reversedListHead = reverseListRecursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return reversedListHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        // return reverseListIterative(head);
        return reverseListRecursive(head);
    }
};