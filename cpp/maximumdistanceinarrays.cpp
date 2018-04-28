class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int left = arrays[0].front(), right = arrays[0].back();
        int MAX = 0;
        for (int i = 1; i < arrays.size(); i++) {
            MAX = max(MAX, abs(arrays[i].front()-right));
            MAX = max(MAX, abs(arrays[i].back()-left));
            left = min(left, arrays[i].front());
            right = max(right, arrays[i].back());
        }
        return MAX;
    }
};
