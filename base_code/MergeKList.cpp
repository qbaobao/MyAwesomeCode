/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct comp{
    bool operator()(const ListNode* listN1, const ListNode* listN2) 
    {
        return listN1->val > listN2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listNum = lists.size();
        ListNode* head = nullptr;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        ListNode* cur = nullptr;
        ListNode* pre = nullptr;
        //创建最小堆
        for (size_t i = 0; i < listNum; i++) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (head == nullptr) {
                head = pre = cur;
            } else {
                pre->next = cur;
                pre = pre->next;
            }
            if(cur->next) {
                pq.push(cur->next);
            }
        }
        return head;
        
    }
};