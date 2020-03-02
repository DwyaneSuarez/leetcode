class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size)
            return -1;
        Node *ret = head;
        for (int i = 0; i < index; ++i)
            ret = ret->next;
        return ret->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *cur = new Node(val);
        cur->next = head;
        head = cur;
        ++size;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node *cur = head;
        for (int i = 0; i < size - 1; ++i)
            cur = cur->next;
        Node *node = new Node(val);
        cur->next = node;
        ++size;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        if (index <= 0)
            addAtHead(val);
        else if (index == size)
            addAtTail(val);
        else {
            Node *cur = head;
            for (int i = 0; i < index - 1; ++i)
                cur = cur->next;
            Node *node = new Node(val);
            node->next = cur->next;
            cur->next = node;
            ++size;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= 0 && index < size) {
            if (index == 0) {
                Node *tmp = head;
                head = head->next;
                delete tmp;
            } else {
                Node *cur = head;
                for (int i = 0; i < index - 1; ++i)
                    cur = cur->next;
                Node *tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            --size;
        }
    }

private:
    struct Node {
        int val;
        Node *next;
        Node(int v) {
            val = v;
            next = NULL;
        }
    };
    Node *head;
    int size;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */