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
    int checkHeight(TreeNode* root) {
        if (!root) return 0;
        int left = checkHeight(root->left);
        if (left == -1) return -1;
        int right = checkHeight(root->right);
        if (right == -1) return -1;
        
        if (abs(left-right) > 1) return -1;
        return max(left,right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int h = checkHeight(root);
        return h > 0;
    }
};