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
    int postIdx = 0;
    int getInOrderIdx(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == target)
                return i;
        }
        return -1;
    }
    
    TreeNode *buildHelper(vector<int>& inorder, vector<int>& postorder, int start, int end) {
        if (start > end) return nullptr;
        
        TreeNode *node = new TreeNode(postorder[postIdx--]);
        if (start == end) return node;
        
        int idx = getInOrderIdx(inorder, node->val, start, end);
        node->right = buildHelper(inorder, postorder, idx + 1, end);
        node->left = buildHelper(inorder, postorder, start, idx-1);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIdx = postorder.size()-1;
        if (postIdx < 0 ) return nullptr;
        return buildHelper(inorder, postorder, 0, postIdx);
    }
};