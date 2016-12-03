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
    int sumHelper(TreeNode* root, int preSum) {
        if (!root) return 0;
        preSum = preSum* 10 + root->val;
        if (!root->left && !root->right) 
            return preSum;
        else 
            return sumHelper(root->left, preSum) + sumHelper(root->right, preSum);
        
    }


    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int sum = 0;
        return sumHelper(root, sum);
    }
};