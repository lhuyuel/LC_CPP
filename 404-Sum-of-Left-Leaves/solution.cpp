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
    // 理解错题意了= =，这个题是想要求所有是left child的left的和，而不是每个level第一个左侧的leaf的和
    /*
    3
   / \
  9  20
    /  \
   15   7
    */
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *tmp = stk.top();
            stk.pop();
            if (tmp->left) {
                if (!tmp->left->left && !tmp->left->right)
                    sum += tmp->left->val;
                else
                    stk.push(tmp->left);
            }
            if (tmp->right){
                // push to stack only when the right is not a leaf
                if (tmp->right->left || tmp->right->right) 
                    stk.push(tmp->right);
            }
        }
        return sum;
    }
};