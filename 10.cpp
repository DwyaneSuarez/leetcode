#include <bits/stdc++.h>
using namespace std;
bool isMatch(string s, string p) {
    int ls = s.size();
    int lp = p.size();
    bool dp[ls + 5][lp + 5];
    dp[0][0] = true;
    for (int i = 1; i <= ls; i++)
        dp[i][0] = false;
    for (int i = 1; i <= lp; i++)
        dp[0][i] = i > 1 && p[i - 1] == '*' && dp[0][i - 2];
    for (int i = 1; i <= ls; i++) {
        for (int j = 1; j <= lp; j++) {
            if (p[j - 1] == '*')
                dp[i][j] = dp[i][j - 2] || (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        }
    }
    return dp[ls][lp];
}
int main() {
    string s, p;
    cin >> s >> p;
    cout << (isMatch(s, p) ? "true" : "false") << endl;
    return 0;
}
