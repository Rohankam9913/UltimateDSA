class Solution {
public:
    TreeNode *solve(TreeNode *root,TreeNode *p,TreeNode *q) {
        if(!root) {
            return NULL;
        }

        if(root == p || root == q) {
            return root;
        }

        TreeNode *left = solve(root->left,p,q);
        TreeNode *right = solve(root->right,p,q);

        if(left && right) {
            return root;
        }

        if(left) {
            return left;
        }

        return right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};