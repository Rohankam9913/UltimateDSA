// Iterative Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) {
            return list2;
        }

        if(!list2) {
            return list1;
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;

        while(list1 && list2) {
            if(list1->val <= list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }

            ptr = ptr->next;
        }

        while(list1) {
            ptr->next = list1;
            list1 = list1->next;
            ptr = ptr->next;
        }

        while(list2) {
            ptr->next = list2;
            list2 = list2->next;
            ptr = ptr->next;
        }

        ptr->next = NULL;
        return dummy->next;
    }
};

// Using Recursive Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) {
            return list2;
        }

        if(!list2) {
            return list1;
        }

        if(list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next,list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1,list2->next);
            return list2;
        }

        return NULL;
    }
};