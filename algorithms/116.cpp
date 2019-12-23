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
        queue<pair<Node*, int>> que;
        if (root)
            que.push({root, 0});
        pair<Node*, int> pre = {nullptr, 0};
        while (!que.empty()) {
            auto cur = que.front();
            que.pop();
            if (pre.first && pre.second == cur.second)
                pre.first->next = cur.first;
            if (cur.first->left)
                que.push({cur.first->left, cur.second + 1});
            if (cur.first->right)
                que.push({cur.first->right, cur.second + 1});
            pre = cur;
        }
        return ret;
    }
};