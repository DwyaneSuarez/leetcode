class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        if (nums.size() == 0)
            return vec;
        deque<int> deq;
        for (int i = 0; i < k; ++i) {
            while (!deq.empty() && deq.back() < nums[i])
                deq.pop_back();
            deq.push_back(nums[i]);
        }
        vec.reserve(nums.size() - k + 1);
        vec.push_back(deq.front());
        for (int i = 1; i <= nums.size() - k; ++i) {
            if (nums[i - 1] == deq.front())
                deq.pop_front();
            while (!deq.empty() && deq.back() < nums[i + k - 1])
                deq.pop_back();
            deq.push_back(nums[i + k - 1]);
            vec.push_back(deq.front());
        }
        return vec;
    }
};