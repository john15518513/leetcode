class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> n1s(nums1.begin(), nums1.end());
        set<int> n2s(nums2.begin(), nums2.end());
        vector<int> res;
        for (auto it = n1s.begin(); it != n1s.end(); it++) {
            if (n2s.find(*it) != n2s.end()) res.push_back(*it);
        }
        return res;
        
    }
};
