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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        bool flip = false;
        vector<int> level;
        int count = toVisit.size();
        while (!toVisit.empty()) {
            TreeNode *tmp = toVisit.front();
            level.push_back(tmp->val);
            toVisit.pop();
            if (tmp->left) toVisit.push(tmp->left);
            if (tmp->right) toVisit.push(tmp->right);
            --count;
            // when count is 0 indicate reached the end of the level
            if (count == 0) {
                if (flip) reverse(level.begin(),level.end());
                result.push_back(level);
                level.clear();
                flip = !flip;
                count = toVisit.size();
            }
        }
        return result;
    }
};