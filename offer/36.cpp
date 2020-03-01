/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return NULL;
        stack<Node*> rec;
        Node *head = NULL;
        Node *cur = root;
        while (cur) {
            rec.push(cur);
            head = cur;
            cur = cur->left;
        }
        cout << head->val << endl;
        Node *pre = NULL;
        while (!rec.empty()) {
            cur = rec.top();
            rec.pop();
            if (pre) {
                pre->right = cur;
                cur->left = pre;
            }
            pre = cur;
            if (cur->right) {
                Node *tmp = cur->right;
                while (tmp) {
                    rec.push(tmp);
                    tmp = tmp->left;
                }
            }
        }
        pre->right = head;
        head->left = pre;
        return head;
    }
};