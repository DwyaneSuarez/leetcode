/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    void copy(Node *src, Node *dest, unordered_map<Node*, Node*> &hash) {
        dest->val = src->val;
        for (auto &neighbor : src->neighbors) {
            if (!hash.count(neighbor)) {
                hash[neighbor] = new Node();
                dest->neighbors.emplace_back(hash[neighbor]);
                copy(neighbor, hash[neighbor], hash);
            } else {
                dest->neighbors.emplace_back(hash[neighbor]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> hash;
        Node *ret = new Node();
        hash[node] = ret;
        copy(node, ret, hash);
        return ret;
    }
};