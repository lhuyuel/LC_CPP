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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> toVisit;
        vector<int> result;
        TreeNode *cur = root;
        while (cur || !toVisit.empty()) {
            if (cur) {
                toVisit.push(cur);
                cur = cur->left;
            }
            else {
                TreeNode *tmp = toVisit.top();
                toVisit.pop();
                result.push_back(tmp->val);
                cur = tmp->right;
            }
        }
        return result;
    }
};