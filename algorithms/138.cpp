/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *ret = nullptr;
        if (!head)
            return ret;
        unordered_map<Node*, Node*> hash;
        hash[nullptr] = nullptr;
        Node *cur = head;
        Node *pre = nullptr;
        Node *dest = nullptr;
        while (cur) {
            dest = new Node(cur->val);
            hash[cur] = dest;
            if (pre)
                pre->next = dest;
            cur = cur->next;
            pre = dest;
        }
        cur = head;
        dest = hash[cur];
        while (cur) {
            dest->random = hash[cur->random];
            cur = cur->next;
            dest = dest->next;
        }
        return hash[head];
    }
};
