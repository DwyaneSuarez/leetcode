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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int len = 0;
        ListNode *cur = head;
        while (cur) {
            ++len;
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; i < len - k; ++i)
            cur = cur->next;
        return cur;
    }
};