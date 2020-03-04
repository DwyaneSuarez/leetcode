class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (true) {
            if (l >= r)
                break;
            int mid = l + (r - l) / 2;
            swap(arr[l], arr[mid]);
            int pivot = arr[l];

            int i = l, j = r;
            while (i < j) {
                while (arr[j] >= pivot && i < j)
                    --j;
                while (arr[i] <= pivot && i < j)
                    ++i;
                if (i < j)
                    swap(arr[i], arr[j]);
            }
            swap(arr[i], arr[l]);
            if (i + 1 == k)
                break;
            else if (i + 1 < k)
                l = i + 1;
            else
                r = i;
        }
        vector<int> ret;
        ret.reserve(k);
        for (int i = 0; i < k; ++i)
            ret.push_back(arr[i]);
        return ret;
    }
};