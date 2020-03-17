class Solution {
public:
    int strToInt(string str) {
        int i = 0;
        int num = 0;
        int len = str.size();
        while (i < len && isspace(str[i]))
            ++i;
        int flag = 1;
        if (i == len)
            return 0;
        if (str[i] == '+')
            ++i;
        else if (str[i] == '-')
            flag = -1, ++i;
        while (i < len && isdigit(str[i])) {
            int cur = str[i] - '0';
            if (abs(num) > INT_MAX / 10 || (abs(num) == INT_MAX / 10 && cur > INT_MAX % 10))
                return flag == 1 ? INT_MAX : INT_MIN;
            num = num * 10 + flag * cur;
            ++i;
        }
        return num;
    }
};