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
    bool validateBSTHelper(TreeNode* root, int minValue, int maxValue) {
        if (!root) return true;
        if(root->val == INT_MIN && root->left) return false;
        if(root->val == INT_MAX && root->right) return false;
        if (root->val < minValue || root->val > maxValue) return false;
        return validateBSTHelper(root->left, minValue, root->val-1) && validateBSTHelper(root->right, root->val+1, maxValue);
    }

    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return validateBSTHelper(root, INT_MIN, INT_MAX);
    }
};