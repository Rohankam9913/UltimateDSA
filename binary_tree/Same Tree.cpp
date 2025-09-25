// Using DFS

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        }

        if(!p || !q) {
            return false;
        }

        if(p->val != q->val) {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
    }
};

// Using BFS

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) {
            return true;
        }

        if(!p || !q) {
            return false;
        }

        queue<TreeNode*>que1;
        que1.push(p);

        queue<TreeNode*>que2;
        que2.push(q);

        while(!que1.empty() && !que2.empty()) {
            TreeNode *first = que1.front();
            que1.pop();

            TreeNode *second = que2.front();
            que2.pop();

            if(first->val != second->val) {
                return true;
            }

            if(first->left && second->left) {
                que1.push(first->left);
                que2.push(second->left);
            } else if(!first->left || !second->left){
                returnn false;
            }

            if(first->right && second->right) {
                que1.push(first->right);
                que2.push(second->right);
            } else if(!first->right || !second->right) {
                return false;
            }
        }

        return true;
    }
};