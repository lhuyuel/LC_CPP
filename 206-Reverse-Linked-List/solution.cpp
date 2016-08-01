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
        ListNode* nxt = head->next;
        while (head) {
            nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }
        return pre;
    }
};