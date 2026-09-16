class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* next = curr->next; // save next node before overwriting
            curr->next = prev;           // reverse the link
            prev = curr;                 // move prev forward
            curr = next;                 // move curr forward
        }
        
        return prev; // prev is the new head
    }
};