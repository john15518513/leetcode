class Solution {
public:
    int d(vector<int> &p, vector<int> &q) {
        return pow(p[0]-q[0],2) + pow(p[1]-q[1],2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s({d(p1,p2), d(p1,p3), d(p1,p4), d(p2,p3), d(p2,p4), d(p3,p4)});
        return s.find(0) == s.end() && s.size() == 2;
    }
};
