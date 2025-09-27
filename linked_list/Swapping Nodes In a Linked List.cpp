// Using Length

class Solution {
public:
    int findLength(ListNode *head) {
        int len = 0;
        while(head) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next) {
            return head;
        }

        int n = findLength(head);

        ListNode *first = NULL, *second = NULL;
        ListNode *cur = head;

        int positionFirst = k, positionSecond = n-k+1;
        int count = 1;

        while(cur) {
            if(count == positionFirst) {
                first = cur;
            } else if(count == positionSecond) {
                second = cur;
            }
            cur = cur->next;
            count++;
        }   

        swap(first->val,second->val);

        return head;
    }
};

// Using One Pass

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next) {
            return head;
        }

        ListNode *first = head;

        for(int i = 1;i < k;i++) {
            first = first->next;
        }

        ListNode *ptr = first;
        ListNode *second = head;

        while(ptr->next) {
            second = second->next;
            ptr = ptr->next;
        }        

        swap(first->val,second->val);
        return head;
    }
};