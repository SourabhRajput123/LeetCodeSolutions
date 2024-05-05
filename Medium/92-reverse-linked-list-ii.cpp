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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
                if (head == nullptr) {
            return nullptr;
        }
        
        // Dummy node to handle the case when left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        // Move prev to the node before the left position
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        // Point leftNode to the node at position left
        ListNode* leftNode = prev->next;
        
        // Reverse the sublist from left to right
        for (int i = 0; i < right - left; ++i) {
            ListNode* nextNode = leftNode->next;
            leftNode->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }
        
        return dummy->next;
    }
};