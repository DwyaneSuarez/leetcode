// 第一个栈用来插入队尾元素
// 每当查询弹出队头元素时，如果第二个栈中有元素，直接弹出一个即可
// 否则将第一个栈的所有元素倒装进第二个栈，再弹出一个
// 都没有元素时返回-1

class CQueue {
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if (!stack2.empty()) {
            int ret = stack2.top();
            stack2.pop();
            return ret;
        }
        while (!stack1.empty()) {
            int cur = stack1.top();
            stack1.pop();
            stack2.push(cur);
        }
        if (stack2.empty())
            return -1;
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }
private:
    stack<int> stack1, stack2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */