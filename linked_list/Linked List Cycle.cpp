// Using hasing

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) {
            return false;
        }

        unordered_map<ListNode*,bool>vis;

        while(head != NULL) {
            if(vis[head]) {
                return true;
            } 

            vis[head] = true;
            head = head->next;
        }

        return false;
    }
};

// Using Slow and Fast Pointer

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};