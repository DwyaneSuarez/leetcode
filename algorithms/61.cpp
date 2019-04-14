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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        int len = 0;
        ListNode* cur = head;
        ListNode* last;
        while (cur) {
            last = cur;
            cur = cur->next;
            len++;
        }
        int move = k % len;
        if (move == 0)
            return head;
        ListNode* start = head;
        cur = head;
        ListNode* pre;
        for (int i = 0; i < len - move; i++) {
            pre = cur;
            cur = cur->next;
        }
        last->next = start;
        pre->next = NULL;
        return cur;
    }
};
