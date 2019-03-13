#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    map<int, int> cnt;
    for (int i = 0; i < len; i++)
        cnt[nums[i]]++;
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    len = nums.size();
    vector<vector<int>> ans;
    vector<int> cur;
    for (int i = 0; i < len; i++) {
        if (cnt[nums[i]] >= 2) {
            int c = 0 - nums[i] * 2;
            if (c >= nums[i]) {
                cnt[nums[i]] -= 2;
                if (cnt[c] > 0) {
                    cur.clear();
                    cur.push_back(nums[i]);
                    cur.push_back(nums[i]);
                    cur.push_back(c);
                    ans.push_back(cur);
                }
                cnt[nums[i]] += 2;
            }
        }
        for (int j = i + 1; j < len; j++) {
            int c = 0 - nums[i] - nums[j];
            if (c >= nums[j]) {
                cnt[nums[i]]--;
                cnt[nums[j]]--;
                if (cnt[c] > 0) {
                    cur.clear();
                    cur.push_back(nums[i]);
                    cur.push_back(nums[j]);
                    cur.push_back(c);
                    ans.push_back(cur);
                }
                cnt[nums[i]]++;
                cnt[nums[j]]++;
            }
        }
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<vector<int>> ans = threeSum(nums);
    for (auto iter1 : ans) {
        for (auto iter2 : iter1) {
            cout << iter2 << ' ';
        }
        cout << endl;
    }
    return 0;
}
