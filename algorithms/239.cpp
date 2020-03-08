class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return vector<int>();
        deque<int> deq;
        for (int i = 0; i < k; ++i) {
            int cur = nums[i];
            while (!deq.empty() && deq.back() < cur)
                deq.pop_back();
            deq.push_back(cur);
        }
        vector<int> vec(nums.size() - k + 1);
        vec[0] = deq.front();
        for (int i = 1; i < nums.size() - k + 1; ++i) {
            int f = nums[i - 1];
            if (f == deq.front())
                deq.pop_front();
            int b = nums[i + k - 1];
            while (!deq.empty() && deq.back() < b)
                deq.pop_back();
            deq.push_back(b);
            vec[i] = deq.front();
        }
        return vec;
    }
};