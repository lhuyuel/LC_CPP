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
    vector<TreeNode*> buildTree(int start, int end) {
        vector<TreeNode*> result;
        if (start == end) {
            result.push_back(new TreeNode(start));
            return result;
        }
        
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        
        for(int i = start; i <= end; ++i) {
            for (auto leftSide : buildTree(start,i-1)) {
                for (auto rightSide: buildTree(i+1,end)) {
                    TreeNode * node = new TreeNode(i);
                    node->left = leftSide;
                    node->right = rightSide;
                    result.push_back(node);
                }
            }
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if (n > 0) 
            result = buildTree(1,n);
        return result;
    }
};