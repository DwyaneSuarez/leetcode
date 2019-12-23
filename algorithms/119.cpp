class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        if (rowIndex < 0)
            return vec;
        vec.emplace_back(1);
        for (int i = 1; i <= rowIndex / 2; ++i) {
            long long tmp = vec[i - 1];
            if (tmp % i == 0)
                tmp = tmp / i * (rowIndex - i + 1);
            else if ((rowIndex - i + 1) % i == 0)
                tmp = tmp * ((rowIndex - i + 1) / i);
            else
                tmp = tmp * (rowIndex - i + 1) / i;
            vec.emplace_back(tmp);
        }
        for (int i = rowIndex / 2 + 1; i < rowIndex + 1; ++i)
            vec.emplace_back(vec[rowIndex - i]);
        return vec;
    }
};