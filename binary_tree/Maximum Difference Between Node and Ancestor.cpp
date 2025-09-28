// Using Brute Force

class Solution {
public:
    void findMaxProd(TreeNode *root, int &ancestor ,long long &maxProd) {
        if(!root) {
            return;
        }

        maxProd = max(maxProd, (long long)abs(ancestor - root->val));
        findMaxProd(root->left, ancestor, maxProd);
        findMaxProd(root->right, ancestor, maxProd);
    }

    void solve(TreeNode *root, long long &maxProd) {
        if(!root) {
            return;
        }

        findMaxProd(root,root->val,maxProd);
        solve(root->left,maxProd);
        solve(root->right,maxProd);    
    }

    int maxAncestorDiff(TreeNode* root) {
        if(!root) {
            return 0;
        }

        if(!root->left && !root->right) {
            return 0;
        }

        long long maxDiff = 0;
        solve(root,maxDiff);

        return maxDiff;
    }
};

// Using Optimal Approach

class Solution {
public:
    void solve(TreeNode *root, int maxV, int minV, int &maxDiff) {
        if(!root) {
            return;
        }

        maxV = max(maxV, root->val);
        minV = min(minV, root->val);

        if(!root->left && !root->right) {
            maxDiff = max(maxDiff, maxV - minV);
            return;
        }

        solve(root->left,maxV,minV,maxDiff);
        solve(root->right,maxV,minV,maxDiff);
    }

    int maxAncestorDiff(TreeNode* root) {
        if(!root) {
            return 0;
        }

        if(!root->left && !root->right) {
            return 0;
        }

        int maxDiff = 0;
        solve(root,root->val,root->val,maxDiff);
        return maxDiff;
    }
};