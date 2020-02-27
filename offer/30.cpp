class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);
        if (mini.empty()) 
            mini.push(x);
        else 
            mini.push(std::min(x, mini.top()));
    }
    
    void pop() {
        data.pop();
        mini.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int min() {
        return mini.top();
    }
private:
    stack<int> data;
    stack<int> mini;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */