class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> vec;
        int num = 1, end = 1;
        for (int i = 0; i < n; ++i)
            end *= 10;
        vec.reserve(end - num);
        while (num < end) {
            vec.push_back(num);
            ++num;
        }
        return vec;
    }
};