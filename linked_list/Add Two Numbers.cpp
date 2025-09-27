class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *newList = NULL, *ptr = NULL;
        int sum = 0, carry = 0;

        while(l1 || l2){
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;

            ListNode *node = new ListNode(sum%10);
            
            if(!ptr) {
                newList = node;
                ptr = node;
            } else {
                ptr->next = node;
                ptr = ptr->next;
            }

            carry = sum/10;
            sum = 0;
        }

        if(carry > 0) {
            ListNode *node = new ListNode(carry);
            ptr->next = node;
            ptr = ptr->next;
        }

        return newList;
    }
};