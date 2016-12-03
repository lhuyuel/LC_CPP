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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2 || l1 && !l2) return l1;
        else if( !l1 && l2 ) return l2;
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val){
                pre = pre->next =l1;
                l1=l1->next;
            }
            else {
                pre = pre->next =l2;
                l2 =l2->next;
            }
        }
        pre->next = (!l1)? l2:l1;
        return dummy->next;
    }
};