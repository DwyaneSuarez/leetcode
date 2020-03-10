class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (auto &num : A)
            sum += num;
        if (sum % 3 != 0)
            return false;            
        vector<int> vec1, vec2;
        int cur = 0;
        for (int i = 0; i < A.size(); ++i) {
            cur += A[i];
            if (cur * 3 == sum)
                vec1.push_back(i);
            if (cur % 2 == 0 && cur / 2 * 3 == sum)
                vec2.push_back(i);
        }
        for (int i = 0; i < vec1.size(); ++i) {
            auto it = upper_bound(vec2.begin(), vec2.end(), vec1[i]);
            if (it != vec2.end() && (*it) + 1 != A.size())
                return true;
        }
        return false;
    }
};