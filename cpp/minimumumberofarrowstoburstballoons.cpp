class Solution {
    struct cmp {
      bool operator()(const pair<int, int>& a, const pair<int, int>& b){
          return a.second < b.second;
      }
    };
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), cmp());
        //for (auto &c: points) cout << c.first << " " << c.second << endl;
        int count = 1;
        int maxRight = points[0].second;
        for (int i = 1; i < points.size(); i++) {
            if (points[i].first <= maxRight) continue;
            else {
                count++;
                maxRight = points[i].second;
            }
        }
        return count;
        
    }
};
