class Solution {
public:
    ListNode* reverse(ListNode* l) {
        ListNode * pre = nullptr;
        ListNode * nxt = nullptr;
        while (l) {
            nxt = l->next;
            l->next = pre;
            pre = l;
            l = nxt;
        }
        return pre;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        ListNode * newHead = new ListNode(0);
        ListNode *l3 = newHead;
        int carry = 0;
        while (l1 || l2 || carry) {
            int c = 0;
            if (l1) {
                c += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                c += l2->val;
                l2 = l2->next;
            }
            c += carry;
            if (c >= 10) {
                carry = 1;
                l3->next = new ListNode(c - 10);
            } 
            else {
                carry = 0;
                l3->next = new ListNode(c);
            }
            
            l3 = l3->next;
        }
        return reverse(newHead->next);
    }
};
