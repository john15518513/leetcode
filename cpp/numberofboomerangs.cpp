class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int cnt = 0;
        unordered_map<int, int> count;
        for (int i = 0; i < points.size(); i++) {
            for (int j = 0; j < points.size(); j++) {
                if (i == j) continue;
                count[getDistance(points[i], points[j])]++;
            }
            for (auto &e: count) {
                cnt += e.second*(e.second-1);
            }
            count.clear();
        }
        return cnt;
    }
    int getDistance(pair<int, int> &a, pair<int, int> &b) {
        return pow(abs(a.first-b.first), 2) + pow(abs(a.second-b.second), 2);
    }
};
