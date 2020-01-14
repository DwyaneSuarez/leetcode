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
    ListNode* insertionSortList(ListNode* head) {
        if (!head)
            return head;
        ListNode *cur = head->next;
        ListNode *curPre = head;
        while (cur) {
            ListNode *posPre = nullptr;
            ListNode *pos = head;
            while (pos != cur && pos->val <= cur->val) {
                posPre = pos;
                pos = pos->next;
            }
            if (pos == cur) {
                curPre = cur;
                cur = cur->next;
                continue;
            }
            curPre->next = cur->next;
            if (posPre)
                posPre->next = cur;
            else
                head = cur;
            ListNode *tmp = cur->next;
            cur->next = pos;
            cur = tmp;
        }
        return head;
    }
};
