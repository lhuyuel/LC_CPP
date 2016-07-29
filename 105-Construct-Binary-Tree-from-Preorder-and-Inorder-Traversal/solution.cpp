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
    int preOrderIdx = 0;
    int getInOrderIdx(vector<int> &inorder, int x, int start, int end){
        for(int i = start; i <= end; ++i){
            if( inorder[i] == x)
                return i;
        }
        return -1;
    }
    
    TreeNode* buildHelper(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        
        
        if (start > end) return nullptr;
        TreeNode *node = new TreeNode(preorder[preOrderIdx++]);
        if (start == end) return node;
        int idx = getInOrderIdx(inorder, node->val, start, end);
        node->left = buildHelper(preorder,inorder, start, idx-1);
        node->right = buildHelper(preorder, inorder, idx +1, end);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildHelper(preorder,inorder, 0, preorder.size()-1);
    }
};