/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 /* Reservoir sampling 
    According to the problem, head is not null*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        head_ = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = head_;
        int val = head_->val, count = 1;
        while (cur) {
            if (rand()%count == 0)
                val = cur->val;
            cur = cur->next;
            ++count;
        }
        return val;
    }
    
private:
    ListNode* head_;
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */