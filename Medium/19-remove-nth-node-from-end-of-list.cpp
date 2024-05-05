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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
                ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move the fast pointer n+1 steps ahead
        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }
        
        // Move both pointers until the fast pointer reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Remove the nth node from the end by adjusting the next pointer
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        
        return dummy->next;
    }
};