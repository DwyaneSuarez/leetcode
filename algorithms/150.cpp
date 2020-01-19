class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> is;
        for (auto &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int n2 = is.top();
                is.pop();
                int n1 = is.top();
                is.pop();
                if (token == "+")
                    is.push(n1 + n2);
                else if (token == "-")
                    is.push(n1 - n2);
                else if (token == "*")
                    is.push(n1 * n2);
                else
                    is.push(n1 / n2);
            } else {
                int n = stoi(token);
                is.push(n);
            }
        }
        return is.empty() ? 0 : is.top();
    }
};
