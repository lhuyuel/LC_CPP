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
    // 适合BFS 
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> toVisit;
        toVisit.push(root);
        toVisit.push(nullptr);
        int minD = 1;
        
        while (!toVisit.empty()) {
            TreeNode* tmp = toVisit.front();
            toVisit.pop();
            if (!tmp) {
                if (toVisit.empty()) break;
                else {
                    toVisit.push(nullptr);
                    ++minD;
                }
            }
            else {
                if (!tmp->left && !tmp->right)
                    return minD;
                if (tmp->left) toVisit.push(tmp->left);
                if (tmp->right) toVisit.push(tmp->right);
            }
        }
        return minD;
    }
};