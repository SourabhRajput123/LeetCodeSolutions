/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
                if (!head || !head->next) return head; // If the list has 0 or 1 nodes, no need to swap
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* first = head;
        ListNode* second = head->next;
        
        while (first && second) {
            // Swap the adjacent nodes
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // Move pointers forward for the next pair
            prev = first;
            first = first->next;
            
            // Check if there is another pair to swap
            if (first) second = first->next;
        }
        
        return dummy->next;
    }
};