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
    bool isSymmetricHelper(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        else if (!t1 || !t2) return false;
        if (t1->val != t2->val) return false;
        return isSymmetricHelper(t1->left, t2->right) && isSymmetricHelper(t1->right, t2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetricHelper(root->left, root->right);
    }
};