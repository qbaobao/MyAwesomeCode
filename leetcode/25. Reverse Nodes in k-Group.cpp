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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 1) {
            return head;
        }
        ListNode* tmp = new ListNode(0xffff);
        tmp->next = head;
        ListNode* fix = tmp;
        ListNode* pre = head;
        ListNode* cur = pre->next;
        ListNode* nnext = cur->next;
        int count = 1;
        int total = 0;
        int len = 0;
        for (; head; len++, head = head->next) ;
        if (k > len) {
            return tmp->next;
        }
        while (cur) {
            cur->next = fix->next;
            fix->next = cur;
            pre->next = nnext;
            cur = nnext;
            nnext = (cur == NULL) ? NULL : cur->next;
            count++;
            if (count == k) {
                fix = pre;
                pre = cur;
                cur = (pre == NULL) ? NULL : pre->next;
                nnext = (cur == NULL) ? NULL : cur->next;
                count = 1;
                total++;
            }
            if (total == len / k) {
                break;
            }
        }
        return tmp->next;
    }
};