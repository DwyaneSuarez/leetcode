#include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height) {
    int ans = 0;
    int l = 0, r = height.size() - 1;
    while (l < r) {
        ans = max(ans, (r - l) * min(height[l], height[r]));
        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> height;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        height.push_back(x);
    }
    cout << maxArea(height) << endl;
    return 0;
}
