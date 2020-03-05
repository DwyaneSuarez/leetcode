class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int dx = coordinates[1][0] - coordinates[0][0];
        int dy = coordinates[1][1] - coordinates[0][1];
        if (dx == 0) {
            for (int i = 2; i < n; ++i)
                if (coordinates[i][0] != coordinates[0][0])
                    return false;
            return true;
        }
        if (dy == 0) {
            for (int i = 2; i < n; ++i)
                if (coordinates[i][1] != coordinates[0][1])
                    return false;
            return true;
        }
        int gcd = __gcd(dx, dy);
        dx /= gcd;
        dy /= gcd;
        if (dx * dy > 0) {
            dx = abs(dx);
            dy = abs(dy);
        } else {
            dx = -abs(dx);
            dy = abs(dy);
        }
        for (int i = 2; i < n; ++i) {
            int cdx = coordinates[i][0] - coordinates[0][0];
            int cdy = coordinates[i][1] - coordinates[0][1];
            if (cdx == 0 && cdy == 0)
                continue;
            if (cdx == 0 || cdy == 0)
                return false;
            int cgcd = __gcd(cdx, cdy);
            cdx /= cgcd; cdy /= cgcd;
            if (cdx * cdy > 0)
                cdx = abs(cdx), cdy = abs(cdy);
            else
                cdx = -abs(cdx), cdy = abs(cdy);
            if (dx != cdx || dy != cdy)
                return false;
        }
        return true;
    }
};