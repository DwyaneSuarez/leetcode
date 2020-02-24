class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        unordered_map<int, int> rec;
        string flag = (long long)numerator * denominator >= 0 ? "" : "-";
        long long ntor = abs((long long)numerator);
        long long dtor = abs((long long)denominator);
        long long pre = ntor / dtor;
        ntor = ntor % dtor;
        if (ntor == 0)
            return flag + to_string(pre);
        string ret;
        while (ntor) {
            if (rec.count(ntor) == 0)
                rec[ntor] = rec.size();
            else {
                int beg = rec[ntor];
                return flag + to_string(pre) + "." + ret.substr(0, beg) + "(" + ret.substr(beg, rec.size() - beg) + ")";
            }
            long long tmp = ntor * 10;
            ret += tmp / dtor + '0';
            ntor = tmp % dtor;
        }
        return flag + to_string(pre) + "." + ret;
    }
};