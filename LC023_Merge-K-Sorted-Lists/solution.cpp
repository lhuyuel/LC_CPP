/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
    solution1: 直接两两merge
    solution2: keep 一个size为k的minHeap，相当于k个list一起merge
 */
class Solution {
public:
    struct cmp{
        bool operator () (ListNode *n1, ListNode* n2) {
            return n1->val > n2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> heap;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) heap.push_back(lists[i]);
        }    
        make_heap(heap.begin(), heap.end(), cmp());
    
        ListNode *head = new ListNode(0);
        ListNode * cur = head;
        while (!heap.empty()) {
            ListNode *tmp = heap.front();
            pop_heap(heap.begin(), heap.end(), cmp());
            heap.pop_back();
            cur->next = tmp; 
            cur = tmp;
            tmp = tmp->next;
            if (tmp) {
                heap.push_back(tmp);
                push_heap(heap.begin(), heap.end(), cmp());
            }
        }
        return head->next;
    }
};
