class Solution {
public:
    void solve(TreeNode *root,int sum,int targetSum,vector<int>path,vector<vector<int>>&paths) {
        if(!root) {
            return;
        }

        sum += root->val;
        path.push_back(root->val);

        if(root->left == NULL && root->right == NULL) {
            if(sum == targetSum) {
                paths.push_back(path);
            }

            return;
        }

        solve(root->left,sum,targetSum,path,paths);
        solve(root->right,sum,targetSum,path,paths);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return {};
        }

        if(!root->left && !root->right) {
            if(root->val == targetSum) {
                return {{root->val}};
            }
        }

        vector<vector<int>>paths;
        vector<int>path;

        solve(root,0,targetSum,path,paths);

        return paths;
    }
};