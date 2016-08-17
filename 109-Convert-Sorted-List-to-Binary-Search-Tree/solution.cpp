/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        
        // find the mid
        ListNode *slow = head, *fast = head, *pre = slow;
        while (fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // break the list in the middle
        pre->next = nullptr;
        
        // create root node
        TreeNode *root = new TreeNode(slow->val);
        
        // set root->left and root->right
        root->left = sortedListToBST(head);
        root->left = sortedListToBST(slow->next);
        
        return root;
    }
};