class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> heap;
        int rest = startFuel;
        int cur = 0;
        int ans = 0;
        for (int i = 0; i < stations.size(); ++i) {
            int dis = stations[i][0] - cur;
            rest -= dis;
            while (rest < 0) {
                if (heap.size() == 0)
                    return -1;
                ++ans;
                rest += heap.top();
                heap.pop();
            }
            heap.push(stations[i][1]);
            cur = stations[i][0];
        }
        int dis = target - cur;
        rest -= dis;
        while (rest < 0) {
            if (heap.size() == 0)
                return -1;
            ++ans;
            rest += heap.top();
            heap.pop();
        }        
        return ans;
    }
};