/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode * pre_head = new ListNode(0);
        pre_head->next = head;
        
        ListNode *pre = pre_head;
        ListNode *cur = head;
        
        while (cur) {
            if (cur->val == val) {
                pre->next = cur->next;
                delete cur;
            }
            else pre = pre->next;
            cur = pre->next;
        }
        return pre_head->next;
    }
};