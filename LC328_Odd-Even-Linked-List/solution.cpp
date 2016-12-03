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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) 
            return head;
            
        ListNode *head2 = head->next; // record the head of l2
        ListNode *l1 = head;
        ListNode *l2 = head->next;
        while (l1 && l1->next && l2 && l2->next) {
            l1->next = l1->next->next;
            l1 = l1->next;
            l2->next = l2->next->next;
            l2 = l2->next;
        }
        
        // Append even nodes to odd nodes
        l1->next = head2;
        return head;
    }
};