class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (que.empty())
            return -1;
        return deq.front();
    }
    
    void push_back(int value) {
        que.push(value);
        while (!deq.empty() && deq.back() < value)
            deq.pop_back();
        deq.push_back(value);
    }
    
    int pop_front() {
        if (que.empty())
            return -1;
        int f = que.front();
        que.pop();
        if (f == deq.front())
            deq.pop_front();
        return f;
    }
private:
    queue<int> que;
    deque<int> deq;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */