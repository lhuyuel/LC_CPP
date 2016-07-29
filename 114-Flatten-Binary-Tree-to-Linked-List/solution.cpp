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
    TreeNode *pre;
    void flatten(TreeNode* root) {
        if (!root) return;
        pre = root;
        if (!root->left && !root->right) return;
        if (root->left) flatten(root->left);
        pre->right = root->right;
        flatten(root->right);
        if (root->left) root->right = root->left;
        root->left = nullptr;
        
    }
};