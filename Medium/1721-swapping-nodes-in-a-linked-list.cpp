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
    ListNode* swapNodes(ListNode* head, int k) {
                ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move the fast pointer k steps ahead
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        
        ListNode* first = fast;
        
        // Move both pointers until the fast pointer reaches the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* second = slow;
        
        // Swap the values of the kth node from the beginning and the kth node from the end
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        
        return dummy->next;
    }
};