class Solution {
public:
    string solve(TreeNode *root, unordered_map<string,int>&mp, vector<TreeNode*>&result) {
        if(!root) {
            return "";
        }

        string subtree = to_string(root->val) + "_" + solve(root->left,mp,result) + "_" + 
                         solve(root->right,mp,result);

        mp[subtree]++;
        if(mp[subtree] == 2) {
            result.push_back(root);
        }

        return subtree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>result;
        unordered_map<string,int>mp;

        solve(root,mp,result);

        return result;
    }
};