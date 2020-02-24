class Solution {
public:
    int ver2vec(string &version, vector<int> &vec) {
        int len = version.size();
        int i = 0;
        int num = 0;
        int ret = 1;
        while (i < len) {
            if (version[i] == '.') {
                vec.push_back(num);
                num = 0;
                ++ret;
            } else
                num = num * 10 + version[i] - '0';
            ++i;
        }
        vec.push_back(num);
        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        int cnt1 = ver2vec(version1, v1);
        int cnt2 = ver2vec(version2, v2);
        v1.resize(max(cnt1, cnt2));
        v2.resize(max(cnt1, cnt2));
        if (v1 < v2)
            return -1;
        else if (v1 == v2)
            return 0;
        else
            return 1;
    }
};