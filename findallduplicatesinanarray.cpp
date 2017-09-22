class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        if (nums.empty()) return vector<int> {};
        vector<int> res;
        for (auto &n: nums) {
            if (nums[abs(n)-1] < 0) res.push_back(abs(n));
            nums[abs(n)-1] *= -1;
        }
        
        return res;
    }
};
