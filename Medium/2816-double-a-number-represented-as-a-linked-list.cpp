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
    ListNode* doubleIt(ListNode* head) {
                // Step 1: Build the integer representation of the number
        long long number = 0;
        ListNode* current = head;
        while (current) {
            number = number * 10 + current->val;
            current = current->next;
        }
        
        // Step 2: Double the integer
        number *= 2;
        
        // Step 3: Create a new linked list for the doubled integer
        ListNode* newHead = nullptr;
        while (number > 0) {
            ListNode* newNode = new ListNode(number % 10);
            newNode->next = newHead;
            newHead = newNode;
            number /= 10;
        }
        
        return newHead ? newHead : new ListNode(0);
    }
};