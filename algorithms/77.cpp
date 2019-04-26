class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (n < 1 || k < 1)
            return ret;
        stack<pair<int, int>> state;
        state.push({0, 0});
        vector<int> vec;
        while (!state.empty()) {
            pair<int, int> s = state.top();
            ++s.second;
            state.pop();
            state.push(s);
            if (s.first == k) {
                ret.push_back(vec);
                state.pop();
                vec.pop_back();
            } else {
                if (s.second > n) {
                    state.pop();
                    vec.pop_back();
                } else {
                    state.push({s.first + 1, s.second});
                    vec.push_back(s.second);
                }
            }
        }
        return ret;
    }
};
