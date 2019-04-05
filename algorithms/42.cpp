class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len <= 2)
            return 0;
        vector<int> peak;
        peak.push_back(0);
        for (int i = 1; i < len - 1; i++) {
            if (height[i] > height[i - 1]) {
                if (height[i] >= height[i + 1])
                    peak.push_back(i);
            } else if (height[i] > height[i + 1]) {
                if (height[i] >= height[i - 1])
                    peak.push_back(i);
            }
        }
        peak.push_back(len - 1);
        vector<int> higher;
        higher.resize(peak.size());
        int p_len = peak.size();
        higher[p_len - 1] = height[peak[p_len - 1]];
        for (int i = p_len - 2; i >= 0; i--)
            higher[i] = max(higher[i + 1], height[peak[i]]);
        int l = peak[0], r;
        int ans = 0;
        for (int i = 1; i < p_len; i++) {
            r = peak[i];
            if (height[l] < height[r] || height[r] == higher[i]) {
                int he = min(height[l], height[r]);
                for (int j = l; j <= r; j++)
                    ans += max(0, he - height[j]);
                l = r;
            }
        }
        return ans;
    }
};
