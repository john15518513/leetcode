class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> numsset;
        vector<int> res;
        for (auto &n: nums) {
            if (numsset.find(n) != numsset.end()) res.push_back(n);
            else numsset.insert(n);
        }
        for (int i = 0; i < nums.size(); i++)
            if (numsset.find(i+1) == numsset.end()) res.push_back(i+1);
        return res;
    }
};
