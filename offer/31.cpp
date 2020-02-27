class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> intStack;
        int i = 0, n = pushed.size();
        for (auto elem: popped) {
            if (intStack.empty() || intStack.top() != elem) {
                while (i < n && pushed[i] != elem) {
                    intStack.push(pushed[i]);
                    ++i;
                }
                if (i == n || pushed[i] != elem)
                    return false;
                ++i;
            } else
                intStack.pop();
        }
        return true;
    }
};