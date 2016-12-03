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
    
    // f(n) = max( f(n->left) + f(n->right) , 
    //            n->val + f(n->left->left) + f(n->left->right) + f(n->right->left) + f(n->right->right) )
    
    /*
     3      max( rob(2) + rob(3) = 6, 3 + rob(null) + rob(3) + rob(null) + rob(1) = 7) = 7
    / \         - rob(2) = max( rob(null) + rob(3), 2 + rob(null) + rob(null)) = 3
   2   3        - rob(3) = max( rob(null) + rob(1), 3 + rob(null +rob(null))) = 3
    \   \ 
     3   1
    
    */

    unordered_map<TreeNode*, int> valTable;
    
    int checkTable(TreeNode* node) {
        if (valTable.find(node) != valTable.end())
            return valTable[node];
        valTable[node] = rob(node);
        return valTable[node];
    }
    
    int rob(TreeNode* root) {
        
        if (!root) return 0;
        int skipThisNode = checkTable(root->left) + checkTable(root->right);

        int robThisNode = root->val;
        if (root->left) 
            robThisNode += ( checkTable(root->left->left) + checkTable(root->left->right));
        if (root->right)
            robThisNode += (checkTable(root->right->left) + checkTable(root->right->right));
        return max(skipThisNode, robThisNode);
    }
};