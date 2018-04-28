class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int minV = INT_MAX;
        for (int i = 0; i < timePoints.size()-1; i++) {
            minV = min(minV, timeDiff(timePoints[i], timePoints[i+1]));
        }
        minV = min(minV, 1440+timeDiff(timePoints.back(), timePoints.front()));
        return minV;
    }
private:
    int timeDiff(string t1, string t2) {
        int h1 = stoi(t1.substr(0, 2));
        int m1 = stoi(t1.substr(3, 2));
        int h2 = stoi(t2.substr(0, 2));
        int m2 = stoi(t2.substr(3, 2));
        return (h2 - h1) * 60 + (m2 - m1);
    }
};
