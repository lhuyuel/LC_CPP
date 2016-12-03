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

// Test case: 4 ->1 -> 3 ->2
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);

        ListNode *cur = head, *pre = dummy, *nxt = head;
        while (cur) {
            ListNode *curN = dummy->next, *pre = dummy;
            while (curN && curN->val < cur->val) {
                pre = curN;
                curN = curN->next;
            }
            nxt = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = nxt;
        }
        return dummy->next;
    }
};