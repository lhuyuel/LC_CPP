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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode *> toVisit;
        TreeNode *cur = root;
        toVisit.push(cur);
        while (!toVisit.empty()) {
            TreeNode *cur = toVisit.top();
            toVisit.pop();
            result.push_back(cur->val);
            
            if (cur->right) toVisit.push(cur->right);
            if (cur->left) toVisit.push(cur->left);
        }
        return result;
    }
};