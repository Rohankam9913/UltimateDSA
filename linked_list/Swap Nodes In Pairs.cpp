// Using Recursion

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) {
            return NULL;
        }

        ListNode *nxt = head->next;
        if(head->next) {
            head->next = swapPairs(head->next->next);
            nxt->next = head;
        } else {
            nxt = head;
        }
        return nxt;
    }
};