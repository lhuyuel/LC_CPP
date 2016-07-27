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
    int kthSmallest(TreeNode* root, int k) {
        if (!root || k < 1 ) return INT_MIN;
        stack<TreeNode*> stk;
        TreeNode *cur = root;
        stk.push(root);
        while (cur || !stk.empty()) {
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            else {
                cur = stk.top();
                stk.pop();
                if (--k == 0) return cur->val;
                cur = cur ->right;
            }
        }
        return INT_MIN;
    }
};