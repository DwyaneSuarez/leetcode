#include <bits/stdc++.h>
using namespace std;
string convert(string s, int numRows) {
    if (numRows == 1)
        return s;
    int len = s.size();
    string ans = "";
    int loop = numRows * 2 - 2;
    for (int i = 0; i < numRows; i++) {
        if (i == 0) {
            for (int j = 0; j < len; j += loop) {
                ans += s[j];
            }
        } else {
            int offset = loop - 2 * i;
            for (int j = i; j < len; j += loop) {
                ans += s[j];
                if (offset > 0 && j + offset < len)
                    ans += s[j + offset];
            }
        }
    }
    return ans;
}
int main() {
    string s;
    int numRows;
    cin >> s >> numRows;
    cout << convert(s, numRows) << endl;
    return 0;
}

