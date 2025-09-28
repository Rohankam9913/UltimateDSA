class Solution {
public:
    TreeNode *solve(vector<int>&preorder,vector<int>&inorder,int inStart,int inEnd,int preStart,int preEnd) {
        if(inStart > inEnd) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preStart]);
        
        int rootIdx = inStart;
        for(;rootIdx <= inEnd;rootIdx++) {
            if(root->val == inorder[rootIdx]) {
                break;
            }
        }

        int leftSize = rootIdx - inStart;
        int rightSize = inEnd - rootIdx;

        root->left  = solve(preorder, inorder, inStart, rootIdx-1, preStart+1, preStart+leftSize);
        root->right = solve(preorder, inorder, rootIdx+1, inEnd, preEnd-rightSize+1, preEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();    

        if(n == 0) {
            return NULL;
        }

        if(n == 1) {
            return new TreeNode(preorder[0]);
        }

        return solve(preorder,inorder,0,n-1,0,n-1);
    }
};