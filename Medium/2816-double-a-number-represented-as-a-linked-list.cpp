class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        if (!head) return nullptr;
        
        head = reverse(head); // Reverse the list
        
        ListNode* curr = head;
        int carry = 0;
        
        while (curr) {
            int newVal = curr->val * 2 + carry;
            curr->val = newVal % 10;
            carry = newVal / 10;
            if (!curr->next && carry > 0) {
                curr->next = new ListNode(carry); // Add a new node for remaining carry
                break;
            }
            curr = curr->next;
        }
        
        return reverse(head); // Reverse back the list
    }
};
