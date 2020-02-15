// 直接思路是正向扫描每遇到一个空格把后面部分往后挪同时插入%20，这样时间复杂度为O(N^2)
// 所以要避免在中间插入%20，于是考虑反向扫描，先统计字符串中有多少个空格，每一个空格最终字符串的长度就要加2
// 计算出最终字符串长度后利用双指针（一个指针指向原串末尾，另一个指针指向实际的末尾）反向扫描
// 原来是空格的地方用%20填充，否则用原字符填充，这样就避免了大段字符串的移动，时间复杂度O(N)

class Solution {
public:
    string replaceSpace(string s) {
        int space = 0;
        int len = s.size();
        for (int i = 0; i < len; ++i)
            if (s[i] == ' ')
                ++space;
        s.resize(len + space * 2);
        int p = len + space * 2 - 1;
        int q = len - 1;
        while (q >= 0) {
            if (s[q] == ' ') {
                s[p--] = '0';
                s[p--] = '2';
                s[p] = '%';
            } else
                s[p] = s[q];
            q--;
            p--;
        }
        return s;
    }
};