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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if  (!headA || !headB) return nullptr;
        ListNode *l1 = headA, *l2 = headB;
        while (1) {
            if (l1 == l2) return l1;
            if (!l1)  l1 = headB;
            else l1 = l1->next; 
            if (!l2) l2 = headA;
            else l2 = l2->next;
        }
    }
};