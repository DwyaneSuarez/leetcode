/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node *ret = root;
        Node *cur = root;
        while (cur) {
            Node *tmp = cur;
            while (tmp) {
                if (tmp->left && tmp->right)
                    tmp->left->next = tmp->right;
                if (tmp->next) {
                    Node *l = tmp->right ? tmp->right : tmp->left;
                    if (l) {
                        while (tmp->next && !(tmp->next->left) && !(tmp->next->right))
                            tmp = tmp->next;
                        Node *r = nullptr;
                        if (tmp->next)
                            r = tmp->next->left ? tmp->next->left : tmp->next->right;
                        l->next = r;
                    }
                }
                tmp = tmp->next;
            }
            if (cur->left)
                cur = cur->left;
            else if (cur->right)
                cur = cur->right;
            else
                cur = cur->next;
        }
        return ret;
    }
};