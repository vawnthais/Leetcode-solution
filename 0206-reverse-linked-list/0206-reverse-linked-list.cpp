/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL or head->next == NULL) return head;
        ListNode* cur = head;
        ListNode* pre = NULL;

        while (cur) {
         ListNode* next_tmp = cur->next;
         cur->next = pre;
         pre = cur;
         cur = next_tmp;
        }
      return pre;
    }
};