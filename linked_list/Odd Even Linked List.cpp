// Using Extra Space

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }

        if(head->next == NULL) {
            return head;
        }

        int index = 1;
        
        ListNode *odd = new ListNode(-1);
        ListNode *o = NULL;

        ListNode *even = new ListNode(-1);
        ListNode *e = NULL;

        while(head != NULL) {
            if(index % 2 == 0) {
                if(e == NULL) {
                    even->next = head;
                    e = even->next;
                } else {
                    e->next = head;
                    e = e->next;
                }
            } else {
                if(o == NULL) {
                    odd->next = head;
                    o = odd->next;
                } else {
                    o->next = head;
                    o = o->next;
                }
            }
            
            index++;
            head = head->next;
        }

        o->next = even->next;
        e->next = NULL;

        return odd->next;
    }
};

// Using Constant Space

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return NULL;
        }

        if(!head->next) {
            return head;
        }

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = head->next;
        
        while(even && even->next) {
            odd->next = even->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};