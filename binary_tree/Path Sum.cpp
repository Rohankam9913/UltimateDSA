class Solution {
public:
    bool solve(TreeNode *root,int sum,int targetSum) {
        if(!root) {
            return false;
        }

        sum += root->val;

        if(root->left == NULL && root->right == NULL) {
            return sum == targetSum;
        }        

        return solve(root->left,sum,targetSum) || solve(root->right,sum,targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return false;
        }

        if(root->left == NULL && root->right == NULL) {
            return root->val == targetSum;
        }

        return solve(root,0,targetSum);
    }
};