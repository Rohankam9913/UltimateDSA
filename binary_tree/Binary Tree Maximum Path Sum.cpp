class Solution {
public:
    int solve(TreeNode *root, int &result) {
        if(!root) {
            return 0;
        }

        int left  = solve(root->left,result);
        int right = solve(root->right,result);

        int convergedPath = root->val + left + right;
        int answerFromOneSide = root->val + max(left,right);
        int rootAnswer = root->val;

        result = max({result, convergedPath, answerFromOneSide, rootAnswer});
        return max(answerFromOneSide, rootAnswer);
    }

    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        solve(root,result);
        return result;
    }
};