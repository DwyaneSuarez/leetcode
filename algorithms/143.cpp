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
    ListNode* reverseList(ListNode *head) {
        if (!head)
            return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        while (cur) {
            pre->next = cur->next;
            cur->next = head;
            head = cur;
            cur = pre->next;
        }
        return head;
    }
    void mergeLists(ListNode *p1, ListNode *p2) {
        bool state = true;
        ListNode *t1 = p1;
        ListNode *t2 = p2;
        ListNode *cur = t1;
        while (cur) {
            if (state) {
                ListNode *tmp = t1->next;
                t1->next = t2;
                cur = t2;
                t1 = tmp;;
            } else {
                ListNode *tmp = t2->next;
                t2->next = t1;
                cur = t1;
                t2 = tmp;
            }
            state = !state;
        }
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        if (slow == head)
            return;
        ListNode *mid = reverseList(slow);
        mergeLists(head, mid);
    }
};
