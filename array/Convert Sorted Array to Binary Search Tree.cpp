class Solution {
public:
    TreeNode *solve(vector<int>&nums,int start, int end) {
        if(start > end) {
            return NULL;
        }

        if(start == end) {
            return new TreeNode(nums[start]);
        }

        int mid = start + (end-start)/2;
        TreeNode *root = new TreeNode(nums[mid]);

        root->left  = solve(nums,start,mid-1);
        root->right = solve(nums,mid+1,end);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return NULL;
        }

        if(n == 1) {
            return new TreeNode(nums[0]);
        }

        return solve(nums,0,n-1);
    }
};