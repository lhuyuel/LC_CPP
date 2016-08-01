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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p, *deleteNode;
        p = head;
        while( p && p->next ){
            while( p->next && p->val == p->next->val){
                deleteNode = p->next;
                p->next = p->next->next;
                delete deleteNode;
            }
            p = p->next;
        }
        return head;
    }
};