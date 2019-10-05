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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* tmp = new ListNode(0xffff);
        tmp->next = head;

        ListNode* pre = tmp;
        ListNode* cur = head;
        ListNode* nnext = cur->next;

        while (cur && cur->next) {
            pre->next = nnext;
            cur->next = nnext->next;
            nnext->next = cur;
            pre = cur;
            cur = cur->next;
            nnext = (cur == NULL) ? NULL : cur->next;
        }
        return tmp->next;
    }
};