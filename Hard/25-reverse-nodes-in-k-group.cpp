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
    ListNode* reverseKGroup(ListNode* head, int k) {
                if (!head || k == 1) return head; // No need to reverse
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        int count = 0;
        while (curr != nullptr) {
            ++count;
            curr = curr->next;
        }
        
        while (count >= k) {
            curr = prev->next;
            ListNode* nextGroupStart = curr;
            ListNode* next = nullptr;
            ListNode* prevGroupEnd = prev;
            
            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            prevGroupEnd->next = prev; // Connect the end of the previous group to the start of the reversed group
            nextGroupStart->next = curr; // Connect the end of the reversed group to the start of the next group
            
            prev = nextGroupStart;
            count -= k;
        }
        
        return dummy->next;
    }
};