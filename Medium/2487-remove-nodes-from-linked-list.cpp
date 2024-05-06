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
    ListNode* removeNodes(ListNode* head) {
                // Reverse the linked list
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // Traverse the reversed list and remove nodes with a greater value to the right
        ListNode* dummy = new ListNode(0);
        dummy->next = prev;
        ListNode* maxNode = dummy;
        curr = prev;
        while (curr != nullptr) {
            if (curr->val < maxNode->val) {
                maxNode->next = curr->next;
            } else {
                maxNode = curr;
            }
            curr = curr->next;
        }
        
        // Reverse the modified list to restore the original order
        prev = nullptr;
        curr = dummy->next;
        next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};