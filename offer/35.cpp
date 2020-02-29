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
        unordered_map<Node*, Node*> hash;
        Node *cur = head;
        Node *pre = NULL;
        while (cur) {
            Node *cp = new Node(cur->val);   
            hash[cur] = cp;
            if (pre)
                hash[pre]->next = cp;
            pre = cur;
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            hash[cur]->random = hash[cur->random];
            cur = cur->next;
        }
        return head ? hash[head] : NULL;
    }
};