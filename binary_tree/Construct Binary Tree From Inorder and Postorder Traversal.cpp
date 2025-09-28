class Solution {
public:
    int n;

    TreeNode *solve(vector<int>&inorder,vector<int>&postorder,int inStart,int inEnd,int postStart,int postEnd) {
        if(inStart > inEnd) {
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[postEnd]);

        int rootIdx = inStart;
        for(;rootIdx <= inEnd;rootIdx++) {
            if(root->val == inorder[rootIdx]) {
                break;
            }
        }

        int leftSize  = rootIdx - inStart;
        int rightSize = inEnd - rootIdx;

        root->left  = solve(inorder, postorder, inStart, rootIdx-1, postStart, postStart+leftSize-1);
        root->right = solve(inorder, postorder, rootIdx+1, inEnd, postEnd-rightSize, postEnd-1);
         
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        n = inorder.size();

        if(n == 0) {
            return NULL;
        }

        if(n == 1) {
            return new TreeNode(postorder[0]);
        }

        return solve(inorder,postorder,0,n-1,0,n-1);
    }
};