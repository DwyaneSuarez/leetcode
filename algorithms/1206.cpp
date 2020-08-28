struct Node {
    int val;
    Node *right;
    Node *down;
    Node(int v, Node *r, Node *d) {
        val = v;
        right = r;
        down = d;
    }  
};
class Skiplist {
public:
    Skiplist() {
        level = 0;
        head = nullptr;
    }
    
    bool search(int target) {
        Node *cur = head;
        while (cur) {
            while (cur->right && cur->right->val < target) {
                cur = cur->right;
            }
            if (cur->right && cur->right->val == target) return true;
            cur = cur->down;
        }
        return false;
    }
    
    void add(int num) {
        int curLevel = 1;
        while (curLevel <= level && (rand() & 1) == 0) ++curLevel;
        if (curLevel > level) {
            level = curLevel;
            head = new Node(num, nullptr, head);
        }
        Node *cur = head;
        Node *pre = nullptr;
        for (int i = level; i >= 1; --i) {
            while (cur->right && cur->right->val < num) cur = cur->right;
            if (i <= curLevel) {
                Node *tmp = cur->right;
                cur->right = new Node(num, tmp, nullptr);
                cur->right->right = tmp;
                if (pre) {
                    pre->down = cur->right;
                }
                pre = cur->right;
            }
            cur = cur->down;
        }
    }
    
    bool erase(int num) {
        Node *cur = head;
        bool seen = false;
        while (cur) {
            while (cur->right && cur->right->val < num) cur = cur->right;
            if (cur->right && cur->right->val == num) {
                Node *tmp = cur->right;
                cur->right = cur->right->right;
                seen = true;
                delete tmp;
            }
            cur = cur->down;
        }
        return seen;
    }
private:
    int level;
    Node *head;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */