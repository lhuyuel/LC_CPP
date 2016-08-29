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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(0);
        ListNode *tail  = dummy, *cur = head, *nxt = cur, *pre = dummy;
        dummy->next = head;
        while (cur && cur->val < x) {
            tail = cur;
            cur = cur->next;
        }
        while (cur) {
            nxt = cur->next;
            if (cur->val < x) {
                pre->next = cur->next;
                cur->next = tail->next;
                tail->next = cur;
                tail = cur;
            }
            else pre = cur;
            cur = nxt;
        }
        return dummy->next;
    }
};