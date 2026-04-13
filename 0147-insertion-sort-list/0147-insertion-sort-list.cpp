class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        ListNode* tmp = new ListNode(0);
        while(cur) {
            ListNode* pre = tmp;
            while (pre->next && pre->next->val < cur->val) {
                pre = pre->next;
            }
            ListNode* tmp1 = cur->next;
            cur->next = pre->next;
            pre->next = cur;

            cur = tmp1;
        }
        ListNode* sorted = tmp->next;
        delete tmp;
        return sorted;
    }
};