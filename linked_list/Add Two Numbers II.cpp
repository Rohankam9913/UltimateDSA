class Solution {
public:
    ListNode *reverseLL(ListNode *cur) {
        ListNode *prev = NULL, *nxt = NULL;
        while(cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);

        ListNode *head = NULL;

        int sum = 0, carry = 0;

        while(l1 || l2 || carry) {
            sum = carry;

            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode *node = new ListNode(sum%10);
            node->next = head;
            head = node;

            carry = sum/10;
        }

        return head;
    }
};