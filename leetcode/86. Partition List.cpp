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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *tmp;
        ListNode *bigPre = dummy;
        ListNode *smallPre = head;
        for (; bigPre->next && bigPre->next->val < x; bigPre = bigPre->next) ;
        smallPre = bigPre;
        while (smallPre->next) {
            if (smallPre->next->val < x) {
                tmp = smallPre->next;
                smallPre->next = tmp->next;
                tmp->next = bigPre->next;
                bigPre->next = tmp;
                bigPre = bigPre->next;
            } else {
                smallPre = smallPre->next;
            }
        }
        return dummy->next;
    }
};