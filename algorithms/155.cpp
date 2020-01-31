class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        data.push(x);
        if (minData.empty())
            minData.push(x);
        else
            minData.push(min(x, minData.top()));
    }

    void pop() {
        data.pop();
        minData.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minData.top();
    }
private:
    stack<int> data;
    stack<int> minData;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
