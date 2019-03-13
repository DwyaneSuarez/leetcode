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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;
        ListNode* temp;
        if (l1->val > l2->val) {
            temp = l1;
            l1 = l2;
            l2 = temp;
        }
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* pre;
        while (p != NULL) {
            if (p->val <= q->val) {
                pre = p;
                p = p->next;
            } else {
                pre->next = q;
                temp = p;
                p = q;
                q = temp;
            }
        }
        pre->next = q;
        return l1;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0)
            return NULL;
        while (len > 1) {
            for (int i = 0; i < len / 2; i++) {
                if (i == len - 1 - i)
                    continue;
                lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
            }
            len = (len + 1) / 2;
        }
        return lists[0];
    }
};

