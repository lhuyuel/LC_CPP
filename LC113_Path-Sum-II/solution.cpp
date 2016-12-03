/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void pathSumHelper(TreeNode *root, int target, vector<int> path, vector<vector<int>> &result) {
        if (!root) return;
        target -= root->val;
        
        path.push_back(root->val);
        
        // found a path
        if (target == 0 && !root->left && !root->right)
            result.push_back(path);
        
        pathSumHelper(root->left, target, path, result);
        pathSumHelper(root->right, target, path,result);
        
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> result;
        pathSumHelper(root, sum, path, result);
        return result;
    }
};