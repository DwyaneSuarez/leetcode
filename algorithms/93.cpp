class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        int len = s.size();
        if (len == 0)
            return ret;
        for (int i = 1; i <= min(3, len - 3); ++i) {
            string sa = s.substr(0, i);
            if (sa == "")
                continue;
            int a = stoi(sa);
            if (a > 255 || to_string(a) != sa)
                continue;
            for (int j = i + 1; j <= min(i + 3, len - 2); ++j) {
                string sb = s.substr(i, j - i);
                if (sb == "")
                    continue;
                int b = stoi(sb);
                if (b > 255 || to_string(b) != sb)
                    continue;
                for (int k = j + 1; k <= min(j + 3, len - 1); ++k) {
                    string sc = s.substr(j, k - j);
                    if (sc == "")
                        continue;
                    int c = stoi(sc);
                    if (c > 255 || to_string(c) != sc)
                        continue;
                    string sd = s.substr(k);
                    if (sd.size() > 3 || sd == "")
                        continue;
                    int d = stoi(sd);
                    if (d <= 255 && to_string(d) == sd) {
                        ret.emplace_back(sa + "." + sb + "." + sc + "." + sd);
                    }
                }
            }
        }
        return ret;
    }
};
