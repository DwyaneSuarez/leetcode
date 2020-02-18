class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        if (n == 0)
            return 0;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (numbers[mid] < numbers[r]) 
                r = mid;
            else if (numbers[mid] > numbers[r])
                l = mid + 1;
            else
                --r;
        }
        return numbers[l];
    }
};