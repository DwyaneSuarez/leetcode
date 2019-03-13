#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void printList(ListNode* cur) {
    while (cur != NULL) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
}
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
int main() {
    int n;
    cin >> n;
    ListNode* l1 = new ListNode(0);
    ListNode* l2 = new ListNode(0);
    ListNode* pre = l1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            l1->val = x;
            pre = l1;
        } else {
            ListNode* newNode = new ListNode(x);
            pre->next = newNode;
            pre = pre->next;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) {
            l2->val = x;
            pre = l2;
        } else {
            ListNode* newNode = new ListNode(x);
            pre->next = newNode;
            pre = pre->next;
        }
    }
    l1 = mergeTwoLists(l1, l2);
    printList(l1);
    return 0;
}
