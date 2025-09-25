class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) {
            return NULL;
        }

        if(!head->next && head->val == 0) {
            return NULL;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int,ListNode*>mp;
        mp[0] = dummy;

        int pSum = 0;

        while(head) {
            pSum += head->val;

            if(mp.find(pSum) != mp.end()) {
                ListNode *prev = mp[pSum];
                ListNode *ptr = prev;
                int sum = pSum;

                while(ptr != head) {
                    ptr = ptr->next;
                    sum += ptr->val;
                    if(mp[sum]) {
                        mp.erase(sum);
                    }
                }

                prev->next = head->next;
            } else {
                mp[pSum] = head;
            }

            head = head->next;
        }

        return dummy->next;
    }
};