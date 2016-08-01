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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* nxt = head->nxt;
        while (head) {
            nxt = head->next;
            head->next = pre;
            pre = head;
            haed = nxt;
        }
        return pre;
    }
};