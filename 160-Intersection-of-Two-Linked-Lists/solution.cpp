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
    // 思路是l1走到第一个list结尾后转到第二个list的开头，l2走到第二个list结尾后转到第一个list开头
    // 当l1于l2相等时返回。对于没有intersection的情况，会返回nullptr因为l1, l2都会等于结尾null。
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