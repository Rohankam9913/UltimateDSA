// Using Length

class Solution {
public:
    int findLength(ListNode *head) {
        int length = 0;

        while(head != NULL) {
            length++;
            head = head->next;
        }

        return length;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        int length = findLength(head);
        
        ListNode *cur = head;
        ListNode *prev = NULL;

        for(int i = 0;i < length/2;i++) {
            prev = cur;
            cur = cur->next;
        }

        prev->next = cur->next;
        delete cur;

        return head;
    }
};

// Using Slow and Fast Pointer

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode *prev = NULL;
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }        

        prev->next = slow->next;
        delete slow;

        return head;
    }
};