class Solution {
public:
    vector<ListNode*>findMiddle(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return {slow,prev};
    }

    TreeNode *transform(ListNode *head) {
        if(!head) {
            return NULL;
        }

        vector<ListNode*>vec = findMiddle(head);
        TreeNode *root = new TreeNode(vec[0]->val);

        if(vec[1]) {
            vec[1]->next = NULL;
            root->left = transform(head);
        }

        root->right = transform(vec[0]->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) {
            return NULL;
        }

        if(!head->next) {
            return new TreeNode(head->val);
        }

        return transform(head);
    }
};