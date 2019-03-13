#include <bits/stdc++.h>
using namespace std;
string intToRoman(int num) {
    string ans = "";
    int digit[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string ch[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int idx = 12;
    while (idx >= 0 && num > 0) {
        if (num >= digit[idx]) {
            ans += ch[idx];
            num -= digit[idx];
        } else {
            idx--;
        }
    }
    return ans;
}
int main() {
    int num;
    cin >> num;
    cout << intToRoman(num) << endl;
    return 0;
}
