/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *levelStart = root;
        TreeLinkNode *cur = root;
        root->next = nullptr;
        while (levelStart) {
            levelStart = cur->left;
            while (cur) {
                if (cur->left && cur->right) {
                    cur->left->next = cur->right;
                    cur->right->next = cur->next ? cur->next->left : nullptr;
                    cur = cur->next;
                }
                if (!cur) {
                    cur = levelStart;
                }
            }
        }
        
    }
};