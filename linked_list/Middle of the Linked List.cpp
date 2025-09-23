// Using Length of the array

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

    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        int length = findLength(head);
        
        for(int i = 0;i < length/2;i++) {
            head = head->next;
        }

        return head;
    }
};

// Using Fast and Slow Pointer

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};