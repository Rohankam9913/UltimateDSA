class Solution {
public:
    long long findTotalSum(TreeNode *root) {
        if(!root) {
            return 0;
        }

        return root->val + findTotalSum(root->left) + findTotalSum(root->right);
    }

    long long solve(TreeNode *root, long long& totalSum, long long& maxProd) {
        if(!root) {
            return 0;
        }

        long long left = solve(root->left, totalSum, maxProd);
        long long right = solve(root->right, totalSum, maxProd);
        
        long long sum1 = root->val + left + right;
        long long sum2 = totalSum - sum1;

        maxProd = max(maxProd, sum1*sum2);
        return sum1;
    }

    int maxProduct(TreeNode* root) {
        if(!root) {
            return 0;
        }

        if(!root->left && !root->right) {
            return 0;
        }

        long long totalSum = findTotalSum(root);
        long long maxProd = 0;
        int mod = 1e9+7;

        solve(root,totalSum,maxProd);

        return maxProd % mod;
    }
};