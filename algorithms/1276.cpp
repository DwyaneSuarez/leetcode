class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int a = tomatoSlices;
        int b = cheeseSlices;
        int t = a - 2 * b;
        if (t & 1)
            return vector<int>();
        int big = t / 2;
        if (big < 0)
            return vector<int>();
        t = 4 * b - a;
        if (t & 1)
            return vector<int>();
        int small = t / 2;
        if (small < 0)
            return vector<int>();
        return {big, small};
    }
};