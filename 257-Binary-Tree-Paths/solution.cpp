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
    // DFS
    void pathDFS(TreeNode *node, string path,vector<string> &result) {
        // terminate condition
        if (!node->left && !node->right) {
            path += to_string(node->val);
            result.push_back(path);
        }
        
        // dfs
        if (node->left) {
            pathDFS(node->left, path  + to_string(node->val) + "->" , result);
        }
        if (node->right) {
            pathDFS(node->right, path + to_string(node->val) + "->", result);
        }
        
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string path = "";
        if (!root) return result;
        pathDFS(root, path, result);
        return result;
    }
};