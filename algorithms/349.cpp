class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a, b;
        vector<int> ret;
        for (auto num : nums1) 
            a.insert(num);
        for (auto num : nums2)
            b.insert(num);
        for (auto num : nums1)
            if (a.count(num)) {
                if (b.count(num)) 
                    ret.push_back(num);
                a.erase(num);
            }
        return ret;
    }
};