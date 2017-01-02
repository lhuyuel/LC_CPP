/*
Problem: 
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.


**
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
    void longestSeq(TreeNode* root, int curLen, int &maxLen) {
        // update length if longer than current max
        if (curLen > maxLen) maxLen = curLen;
        if (!root)
            return;

        if (root->left) {
            if (root->val + 1 == root->left->val)
                longestSeq(root->left, curLen+1, maxLen);
            else longestSeq(root->left, 1, maxLen);
        }
        if (root->right) {
            if (root->val + 1 == root->right->val)
                longestSeq(root->right, curLen + 1, maxLen);
            else longestSeq(root->right, 1, maxLen);
        }
    }
    
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int maxLen = 0, curLen = 1;
        longestSeq(root, curLen, maxLen);
        return maxLen;
    }
};
