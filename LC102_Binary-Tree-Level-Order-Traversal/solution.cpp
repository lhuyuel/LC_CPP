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
/*  3
   / \
  9  20
    /  \
   15   7     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (!root) return result;
        
        queue<TreeNode *> toVisit;
        toVisit.push(root);
        toVisit.push(nullptr);
        
        vector<int> level;
        while (!toVisit.empty()) {
            TreeNode* cur = toVisit.front();
            toVisit.pop();
            
            if (!toVisit.empty()) {
                // Indicate end of a level 
                if (!cur) {
                    toVisit.push(nullptr);           
                    result.push_back(level);             
                    level.clear();
                }else{
                    level.push_back(cur->val);
                    if (cur->left) toVisit.push(cur->left);
                    if (cur->right) toVisit.push(cur->right);   
                }
            }
        }
        result.push_back(level);
        return result;
    }
};