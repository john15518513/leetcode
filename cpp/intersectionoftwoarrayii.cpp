class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            count[nums1[i]]++;
        }
        for (auto &n: nums2) {
            if (count.find(n) != count.end() and count[n] > 0) {
                res.push_back(n);
                count[n]--;
            }
        }
        return res;
    }
};
