class Solution {
public:
    int partition(vector<int> &nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j < r; ++j) {
            if (nums[j] <= pivot) {
                ++i;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    void quicksort(vector<int> &nums, int l, int r) {
        if (l < r) {
            int mid = partition(nums, l, r);
            quicksort(nums, l, mid - 1);
            quicksort(nums, mid + 1, r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n > 0)
            quicksort(nums, 0, n - 1);
        return nums;
    }
};