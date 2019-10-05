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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }

        ListNode *p, *q, *tmp, *delNode;
        tmp = new ListNode(0xffff);
        tmp->next = head;
        q = tmp;
        p = head;

        for (; n > 0 && p; p = p->next, n--) ;
        for (; p && q->next; p = p->next, q = q->next) ;

        delNode = q->next;
        q->next = q->next->next;
        delete delNode;
        return tmp->next;
    }
};