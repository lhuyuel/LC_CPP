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

    TreeLinkNode *findFirst(TreeLinkNode* start) {
        while (start) {
            if (start->left) return start->left;
            if (start->right) return start->right;
            start = start->next;
        }
        return nullptr;
    }

    void connect(TreeLinkNode *root) {
        if (!root) return nullptr;
        TreeLinkNode *levelStart = root, *cur = root;
        root->next = nullptr;
        while (levelStart) {
            while (cur) {
                if (cur->left) {
                    if (cur->right) {
                        cur->left->next = cur->right;
                        cur->right->next = findFirst(cur);
                    }
                    else 
                        cur->left->next = findFirst(cur);
                }
                cur = cur->next;
            }
            if (!cur) {
                cur = levelStart;
                levelStart = findFirst(levelStart);
            }
        }
    }
};