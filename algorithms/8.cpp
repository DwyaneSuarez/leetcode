class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        int idx = 0;
        while (idx < n && str[idx] == ' ')
            ++idx;
        if (idx == n)
            return 0;
        if (!isdigit(str[idx]) && str[idx] != '+' && str[idx] != '-')
            return 0;
        bool flag = true;
        if (str[idx] == '+')
            ++idx;
        else if (str[idx] == '-')
            flag = false, ++idx;
        int num = 0;
        while (idx < n && isdigit(str[idx])) {
            int cur = str[idx] - '0';
            if (num > INT_MAX / 10)
                return flag ? INT_MAX : INT_MIN;
            if (num == INT_MAX / 10 && cur > INT_MAX % 10)
                return flag ? INT_MAX : INT_MIN;
            num = num * 10 + cur;
            ++idx;
        }
        return flag ? num : -num;
    }
};