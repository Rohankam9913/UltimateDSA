// Using Vector

class Solution {
public:
    int pairSum(ListNode* head) {
        if(!head) {
            return 0;
        }

        vector<int>nodes;
        while(head) {
            nodes.push_back(head->val);
            head = head->next;
        }

        int i = 0, j = nodes.size()-1;
        int maxSum = 0;

        while(i < j) {
            int sum = nodes[i] + nodes[j];
            maxSum = max(maxSum,sum);
            i++, j--;
        }

        return maxSum;
    }
};

// Using Stack

class Solution {
public:
    int pairSum(ListNode* head) {
        if(!head) {
            return 0;
        }

        ListNode *ptr = head;
        stack<int>st;

        while(ptr) {
            st.push(ptr->val);
            ptr = ptr->next;
        }   

        ptr = head;
        int n = st.size();
        int maxSum = 0;

        while(n > n/2) {   
            int sum = ptr->val + st.top();

            ptr = ptr->next;
            st.pop();

            maxSum = max(maxSum,sum);
            n--;
        }

        return maxSum;
    }
};

// Using Reversal

class Solution {
public:
    ListNode *reverse(ListNode *cur) {
        ListNode *prev = NULL, *nxt = NULL;
        while(cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }

        return prev;
    }

    ListNode *findMiddle(ListNode *cur) {
        ListNode *slow = cur;
        ListNode *fast = cur;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    int pairSum(ListNode* head) {
        if(!head) {
            return 0;
        }

        ListNode *mid = findMiddle(head);
        ListNode *revHead = reverse(mid);

        int maxSum = 0;

        while(head->next != revHead) {
            int sum = head->val + revHead->val;
            maxSum = max(maxSum, sum);

            head = head->next;
            revHead = revHead->next;
        }

        if(head && revHead) {
            maxSum = max(maxSum, head->val + revHead->val);
        }

        return maxSum;
    }
};