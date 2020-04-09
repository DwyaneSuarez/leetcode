class Solution {
public:
    string vec2str(vector<int> &cnt) {
        string str;
        for (int i = 9; i >= 1; --i) {
            if (cnt[i] > 0) 
                str += string(cnt[i], static_cast<char>('0' + i));
        }
        if (cnt[0] > 0)
            str += str.empty() ? "0" : string(cnt[0], '0');
        return str;
    }
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int> cnt(10);
        int cnt1 = 0, cnt2 = 0, sum = 0;
        for (auto digit : digits) {
            ++cnt[digit];
            if (digit % 3 == 1)
                ++cnt1;
            if (digit % 3 == 2)
                ++cnt2;
            sum = (sum + digit) % 3;
        }
        if (sum % 3 == 1) {
            if (cnt1 == 0 && cnt2 < 2)
                return "";
            if (cnt1 > 0) {
                for (int i = 1; i < 10; i += 3) {
                    if (cnt[i] > 0) {
                        --cnt[i];
                        return vec2str(cnt);
                    }
                }
            }
            bool b = false;
            for (int i = 2; i < 10; i += 3) 
                if (cnt[i] >= 2) {
                    cnt[i] -= b ? 1 : 2;
                    return vec2str(cnt);
                } else if (cnt[i] == 1) {
                    --cnt[i];
                    if (b)
                        return vec2str(cnt);
                    b = true;
                }
        } else if (sum % 3 == 2) {
            if (cnt2 == 0 && cnt1 < 2)
                return "";
            if (cnt2 > 0) {
                for (int i = 2; i < 10; i += 3) {
                    if (cnt[i] > 0) {
                        --cnt[i];
                        return vec2str(cnt);
                    }
                }
            }
            bool b = false;
            for (int i = 1; i < 10; i += 3) 
                if (cnt[i] >= 2) {
                    cnt[i] -= b ? 1 : 2;
                    return vec2str(cnt);
                } else if (cnt[i] == 1) {
                    --cnt[i];
                    if (b)
                        return vec2str(cnt);
                    b = true;
                }
        }
        return vec2str(cnt);
    }
};