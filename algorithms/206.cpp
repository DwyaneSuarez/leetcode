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
    ListNode* reverseList(ListNode* head) {
        ListNode *vnode = new ListNode(0);
        vnode->next = head;
        ListNode *cur = head;
        while (cur && cur->next) {
            ListNode *tmp = cur->next;
            cur->next = tmp->next;
            tmp->next = vnode->next;
            vnode->next = tmp;
        }
        return vnode->next;
    }

    /* recursion version
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }
    */
};
